
#pragma once

#include <memory>
#include <vector>
#include <cstdlib>
#include <tuple>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshData.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine
{
	class MeshSample
	{
		/* Constructors */

	   public:
		MeshSample(const MeshSample&) = delete;
		MeshSample& operator=(const MeshSample&) = delete;

		MeshSample();

		/* Methods */

	   public:
		std::unique_ptr<MeshData> make(const ShaderProgram& shaderProgram) const;

	   protected:
		virtual std::unique_ptr<std::vector<Vec>> vertPositions3D() const = 0;
		virtual std::unique_ptr<std::vector<Vec>> vertNormals3D() const = 0;
		virtual std::unique_ptr<std::vector<std::tuple<GLuint, GLuint, GLuint>>> triangles() const = 0;
	};
}
