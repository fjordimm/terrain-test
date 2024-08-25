
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSamples/Cube.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::MeshSamples
{
	void Cube::generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const
	{
		/* Vertices */

		{
			if (doVertPositions3D)
			{
				vertPositions3D.push_back(Vec(-1.0f, +1.0f, -1.0f));
				vertPositions3D.push_back(Vec(+1.0f, +1.0f, -1.0f));
				vertPositions3D.push_back(Vec(-1.0f, -1.0f, -1.0f));
				vertPositions3D.push_back(Vec(+1.0f, -1.0f, -1.0f));
				vertPositions3D.push_back(Vec(-1.0f, +1.0f, +1.0f));
				vertPositions3D.push_back(Vec(+1.0f, +1.0f, +1.0f));
				vertPositions3D.push_back(Vec(-1.0f, -1.0f, +1.0f));
				vertPositions3D.push_back(Vec(+1.0f, -1.0f, +1.0f));
			}
			if (doVertNormals3D)
			{
				vertNormals3D.push_back(glm::normalize(Vec(-1.0f, +1.0f, -1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(+1.0f, +1.0f, -1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(-1.0f, -1.0f, -1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(+1.0f, -1.0f, -1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(-1.0f, +1.0f, +1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(+1.0f, +1.0f, +1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(-1.0f, -1.0f, +1.0f)));
				vertNormals3D.push_back(glm::normalize(Vec(+1.0f, -1.0f, +1.0f)));
			}
			if (doVertTextureCoords)
			{
				vertTextureCoords.push_back(Vec2(0.0f, 0.0f));
				vertTextureCoords.push_back(Vec2(1.0f, 0.0f));
				vertTextureCoords.push_back(Vec2(0.0f, 0.0f));
				vertTextureCoords.push_back(Vec2(1.0f, 0.0f));
				vertTextureCoords.push_back(Vec2(0.0f, 1.0f));
				vertTextureCoords.push_back(Vec2(1.0f, 1.0f));
				vertTextureCoords.push_back(Vec2(0.0f, 1.0f));
				vertTextureCoords.push_back(Vec2(1.0f, 1.0f));
			}
		}

		/* Triangles */

		{
			// bottom
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(0, 3, 2));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(3, 0, 1));

			// top
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(6, 5, 4));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(5, 6, 7));

			// front
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(2, 7, 6));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(7, 2, 3));

			// back
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(1, 4, 5));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(4, 1, 0));

			// left
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(0, 6, 4));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(6, 0, 2));

			// right
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(3, 5, 7));
			triangles.push_back(std::make_tuple<GLuint, GLuint, GLuint>(5, 3, 1));
		}
	}
}
