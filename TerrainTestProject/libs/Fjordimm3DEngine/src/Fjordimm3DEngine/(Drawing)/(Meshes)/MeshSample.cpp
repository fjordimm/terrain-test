
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.hpp"

#include <cstring>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	MeshSample::MeshSample() {}

	/* Methods */

	std::unique_ptr<MeshData> MeshSample::make(ShaderProgram const& shaderProgram) const
	{
		bool doPositions3D = shaderProgram.tryGetTrait<ShaderTraits::In3DSpace>() != nullptr;
		bool doNormals3D = shaderProgram.tryGetTrait<ShaderTraits::HasNormals>() != nullptr;
		bool doTextureCoords = shaderProgram.tryGetTrait<ShaderTraits::HasTexture>() != nullptr;

		FJORDIMM3DENGINE_DEBUG_ASSERT(doPositions3D);

		/* Generate the data */

		std::size_t numFloatsPerVertex = 0;

		std::vector<Vec> vertPositions3D;
		if (doPositions3D)
		{ numFloatsPerVertex += 3; }

		std::vector<Vec> vertNormals3D;
		if (doNormals3D)
		{ numFloatsPerVertex += 3; }

		std::vector<Vec2> vertTextureCoords;
		if (doTextureCoords)
		{ numFloatsPerVertex += 2; }

		std::vector<std::tuple<GLuint, GLuint, GLuint>> triangles;

		this->generateData(doPositions3D, vertPositions3D, doNormals3D, vertNormals3D, doTextureCoords, vertTextureCoords, triangles);

		/* Make verts */

		std::size_t vertsVertLen = -1;
		std::size_t vertsLen = -1;
		std::unique_ptr<float[]> verts = nullptr;
		{
			vertsVertLen = vertPositions3D.size();
			if (doPositions3D)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertPositions3D.size() == vertsVertLen); }
			if (doNormals3D)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertNormals3D.size() == vertsVertLen); }
			if (doTextureCoords)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertTextureCoords.size() == vertsVertLen); }

			vertsLen = vertsVertLen * numFloatsPerVertex;

			std::unique_ptr<float[]> _verts(new float[vertsLen]);
			verts = std::move(_verts);

			for (std::size_t i = 0; i < vertsVertLen; i++)
			{
				std::size_t cumlOffset = 0;

				if (doPositions3D)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertPositions3D[i].x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertPositions3D[i].y;
					verts[i * numFloatsPerVertex + cumlOffset + 2] = vertPositions3D[i].z;

					cumlOffset += 3;
				}

				if (doNormals3D)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertNormals3D[i].x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertNormals3D[i].y;
					verts[i * numFloatsPerVertex + cumlOffset + 2] = vertNormals3D[i].z;

					cumlOffset += 3;
				}

				if (doTextureCoords)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertTextureCoords[i].x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertTextureCoords[i].y;

					cumlOffset += 2;
				}
			}
		}

		/* Make elems */

		std::size_t trianglesLen = -1;
		std::size_t elemsLen = -1;
		std::unique_ptr<GLuint[]> elems = nullptr;
		{
			trianglesLen = triangles.size();

			elemsLen = trianglesLen * 3;

			std::unique_ptr<GLuint[]> _elems(new GLuint[elemsLen]);
			elems = std::move(_elems);

			for (std::size_t i = 0; i < trianglesLen; i++)
			{
				elems[i * 3 + 0] = std::get<0>(triangles[i]);
				elems[i * 3 + 1] = std::get<1>(triangles[i]);
				elems[i * 3 + 2] = std::get<2>(triangles[i]);
			}
		}

		/* Finish */

		return std::make_unique<MeshData>(vertsLen, std::move(verts), elemsLen, std::move(elems));
	}
}
