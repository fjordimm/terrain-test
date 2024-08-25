
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

namespace Fjordimm3DEngine
{
	// Forward declarations
	class ShaderProgram;
	
	class MeshSample
	{
		/* Constructors */

	   public:
		MeshSample(MeshSample const&) = delete;
		MeshSample& operator=(MeshSample const&) = delete;

		MeshSample();

		/* Methods */

	   public:
		std::unique_ptr<MeshData> make(ShaderProgram const& shaderProgram) const;

	   protected:
		virtual void generateData(bool doVertPositions3D, std::vector<Vec>& vertPositions3D, bool doVertNormals3D, std::vector<Vec>& vertNormals3D, bool doVertTextureCoords, std::vector<Vec2>& vertTextureCoords, std::vector<std::tuple<GLuint, GLuint, GLuint>>& triangles) const = 0;
		// virtual std::unique_ptr<std::vector<Vec>> vertPositions3D() const = 0;
		// virtual std::unique_ptr<std::vector<Vec>> vertNormals3D() const = 0;
		// virtual std::unique_ptr<std::vector<Vec2>> vertTextureCoords() const = 0;
		// virtual std::unique_ptr<std::vector<std::tuple<GLuint, GLuint, GLuint>>> triangles() const = 0;
	};
}
