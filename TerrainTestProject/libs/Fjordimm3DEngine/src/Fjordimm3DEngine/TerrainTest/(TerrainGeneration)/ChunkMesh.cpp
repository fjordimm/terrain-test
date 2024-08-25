
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"

#include <type_traits>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* LodTransitions Enum Flag */

	LodTransitions operator|(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) | static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator&(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) & static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator^(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) ^ static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator~(LodTransitions the)
	{ return static_cast<LodTransitions>( ~static_cast<std::underlying_type_t<LodTransitions>>(the) ); }

	bool operator==(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<std::underlying_type_t<LodTransitions>>(lhs) == static_cast<std::underlying_type_t<LodTransitions>>(rhs); }

	bool operator!=(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<std::underlying_type_t<LodTransitions>>(lhs) != static_cast<std::underlying_type_t<LodTransitions>>(rhs); }

	/* Constructors */
	
	ChunkMesh::ChunkMesh(TerrainGene& terrainGene, std::size_t size, float chunkScale, int64_t xOff, int64_t yOff, LodTransitions lodTransitions) :
		terrainGene(terrainGene),
		size(size),
		chunkScale(chunkScale),
		xOff(xOff),
		yOff(yOff),
		lodTransitions(lodTransitions)
	{}

	/* Methods */

	void ChunkMesh::generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const
	{
		TerrainGene& terrainGene = this->terrainGene;
		std::size_t size = this->size;
		float chunkScale = this->chunkScale;
		int64_t xOff = this->xOff;
		int64_t yOff = this->yOff;
		LodTransitions lodTransitions = this->lodTransitions;

		// TODO: 65535 was the limit for Unity, but idk the limit for this
		if ((size + 3) * (size + 3) > 65535)
		{ Debug::LogNonfatalError("The chunk size is too big."); }

		if (size % 2 != 0)
		{ Debug::LogNonfatalError("The chunk size must be even."); }

		/* VerticesPre */

		std::vector<Vec> vertsPre;
		vertsPre.resize((size + 3) * (size + 3));
		for (std::size_t c = 0; c < size + 3; c++)
		{
			for (std::size_t r = 0; r < size + 3; r++)
			{
				float xVal = chunkScale * (c - 1);
				float yVal = chunkScale * (r - 1);

				float xValOff = chunkScale * (c - 1 + size * xOff);
				float yValOff = chunkScale * (r - 1 + size * yOff);

				bool doYLodTran = (
					((lodTransitions & LodTransitions::Left) != LodTransitions::None && c < 2)
					|| ((lodTransitions & LodTransitions::Right) != LodTransitions::None && c > size)
				) && r % 2 == 0;

				bool doXLodTran = (
					((lodTransitions & LodTransitions::Bottom) != LodTransitions::None && r < 2)
					|| ((lodTransitions & LodTransitions::Top) != LodTransitions::None && r > size)
				) && c % 2 == 0;

				float zVal;
				if (doYLodTran || doXLodTran)
				{
					float z1 = terrainGene.heightAt(xValOff - (doXLodTran ? chunkScale : 0.0f), yValOff - (doYLodTran ? chunkScale : 0.0f));
					float z2 = terrainGene.heightAt(xValOff + (doXLodTran ? chunkScale : 0.0f), yValOff + (doYLodTran ? chunkScale : 0.0f));
					zVal = (z1 + z2) / 2.0f;
				}
				else
				{
					zVal = terrainGene.heightAt(xValOff, yValOff);
				}

				vertsPre[c * (size + 3) + r] = Vec(xValOff, yValOff, zVal);
			}
		}

		/* Vertices */

		std::size_t numVerts = (size + 1) * (size + 1);
		if (doVertPositions3D)
		{ vertPositions3D.resize(numVerts); }
		if (doVertNormals3D)
		{ vertNormals3D.resize(numVerts); }
		if (doVertTextureCoords)
		{ vertTextureCoords.resize(numVerts); }
		for (std::size_t c = 0; c < size + 1; c++)
		{
			for (std::size_t r = 0; r < size + 1; r++)
			{
				std::size_t newIndex = c * (size + 1) + r;
				Vec vert = vertsPre[(c + 1) * (size + 3) + (r + 1)];

				if (doVertPositions3D)
				{
					vertPositions3D[newIndex] = vert;
				}
				if (doVertNormals3D)
				{
					// TODO:
					vertNormals3D[newIndex] = glm::normalize(vert);
				}
				if (doVertTextureCoords)
				{
					vertTextureCoords[newIndex] = Vec2((float)r, (float)c);
				}
			}
		}

		/* Triangles */

		triangles.resize(2 * size * size);

		for (std::size_t c = 0; c < size; c++)
		{
			for (std::size_t r = 0; r < size; r++)
			{
				GLuint bottomLeft  = (c + 0) * (size + 1) + (r + 0);
				GLuint bottomRight = (c + 1) * (size + 1) + (r + 0);
				GLuint topLeft     = (c + 0) * (size + 1) + (r + 1);
				GLuint topRight    = (c + 1) * (size + 1) + (r + 1);

				triangles[2 * (c * size + r) + 0] = std::make_tuple(topLeft, bottomLeft, topRight);
				triangles[2 * (c * size + r) + 1] = std::make_tuple(bottomRight, topRight, bottomLeft);
			}
		}
	}
}
