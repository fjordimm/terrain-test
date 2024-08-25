
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"

#include <type_traits>

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
	
	ChunkMesh::ChunkMesh(TerrainGene& terrainGene, int32_t size, float chunkScale, int64_t xOff, int64_t yOff, LodTransitions lodTransitions) :
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
		
	}
}
