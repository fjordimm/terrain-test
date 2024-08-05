
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

	std::unique_ptr<MeshData> MeshSample::make(const ShaderProgram& shaderProgram) const
	{
		bool doPositions3D = shaderProgram.tryGetTrait<ShaderTraits::In3DSpace>() != nullptr;
		bool doNormals3D = shaderProgram.tryGetTrait<ShaderTraits::HasNormals>() != nullptr;
		bool doTextureCoords = shaderProgram.tryGetTrait<ShaderTraits::HasTexture>() != nullptr;

		FJORDIMM3DENGINE_DEBUG_ASSERT(doPositions3D);

		/* Make verts */

		std::size_t vertsVertLen = -1;
		std::size_t vertsLen = -1;
		std::unique_ptr<float[]> verts = nullptr;
		{
			std::size_t numFloatsPerVertex = 0;

			std::unique_ptr<const std::vector<Vec>> vertPositions3D = nullptr;
			if (doPositions3D)
			{
				vertPositions3D = this->vertPositions3D();
				numFloatsPerVertex += 3;
			}

			std::unique_ptr<const std::vector<Vec>> vertNormals3D = nullptr;
			if (doNormals3D)
			{
				vertNormals3D = this->vertNormals3D();
				numFloatsPerVertex += 3;
			}

			std::unique_ptr<const std::vector<Vec2>> vertTextureCoords = nullptr;
			if (doTextureCoords)
			{
				vertTextureCoords = this->vertTextureCoords();
				numFloatsPerVertex += 2;
			}

			vertsVertLen = vertPositions3D->size();
			if (doPositions3D)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertPositions3D->size() == vertsVertLen); }
			if (doNormals3D)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertNormals3D->size() == vertsVertLen); }
			if (doTextureCoords)
			{ FJORDIMM3DENGINE_DEBUG_ASSERT(vertTextureCoords->size() == vertsVertLen); }

			vertsLen = vertsVertLen * numFloatsPerVertex;

			std::unique_ptr<float[]> _verts(new float[vertsLen]);
			verts = std::move(_verts);

			for (int i = 0; i < vertsVertLen; i++)
			{
				std::size_t cumlOffset = 0;

				if (doPositions3D)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertPositions3D->at(i).x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertPositions3D->at(i).y;
					verts[i * numFloatsPerVertex + cumlOffset + 2] = vertPositions3D->at(i).z;

					cumlOffset += 3;
				}

				if (doNormals3D)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertNormals3D->at(i).x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertNormals3D->at(i).y;
					verts[i * numFloatsPerVertex + cumlOffset + 2] = vertNormals3D->at(i).z;

					cumlOffset += 3;
				}

				if (doTextureCoords)
				{
					verts[i * numFloatsPerVertex + cumlOffset + 0] = vertTextureCoords->at(i).x;
					verts[i * numFloatsPerVertex + cumlOffset + 1] = vertTextureCoords->at(i).y;

					cumlOffset += 2;
				}
			}
		}

		/* Make elems */

		std::size_t trianglesLen = -1;
		std::size_t elemsLen = -1;
		std::unique_ptr<GLuint[]> elems = nullptr;
		{
			std::unique_ptr<std::vector<std::tuple<GLuint, GLuint, GLuint>>> triangles = this->triangles();

			trianglesLen = triangles->size();

			elemsLen = trianglesLen * 3;

			std::unique_ptr<GLuint[]> _elems(new GLuint[elemsLen]);
			elems = std::move(_elems);

			for (int i = 0; i < trianglesLen; i++)
			{
				elems[i * 3 + 0] = std::get<0>(triangles->at(i));
				elems[i * 3 + 1] = std::get<1>(triangles->at(i));
				elems[i * 3 + 2] = std::get<2>(triangles->at(i));
			}
		}

		/* Finish */

		return std::make_unique<MeshData>(vertsLen, std::move(verts), elemsLen, std::move(elems));
	}
}
