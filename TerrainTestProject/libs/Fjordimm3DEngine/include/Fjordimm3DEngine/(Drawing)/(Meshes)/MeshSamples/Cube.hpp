
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.hpp"

namespace Fjordimm3DEngine::MeshSamples
{
	class Cube : public MeshSample
	{
	   protected:
		std::unique_ptr<std::vector<Vec>> vertPositions3D() const final;
		std::unique_ptr<std::vector<Vec>> vertNormals3D() const final;
		std::unique_ptr<std::vector<Vec2>> vertTextureCoords() const final;
		std::unique_ptr<std::vector<std::tuple<GLuint, GLuint, GLuint>>> triangles() const final;
	};
}
