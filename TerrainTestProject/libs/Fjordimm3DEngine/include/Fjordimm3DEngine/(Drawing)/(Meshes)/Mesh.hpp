
#pragma once

#include <memory>
#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshData.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/MeshSample.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"

namespace Fjordimm3DEngine
{
	// Forward declarations
	class ShaderProgram;

	class Mesh
	{
		/* Constructors */

	   private:
		Mesh() = delete;
		Mesh(const Mesh&) = delete;
		Mesh& operator=(const Mesh&) = delete;
		
		Mesh(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData);

	   public:
		static std::unique_ptr<Mesh> New(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData);
		static inline std::unique_ptr<Mesh> New(ShaderProgram* shaderProgram, const MeshSample& meshSample)
		{ return Mesh::New(shaderProgram, meshSample.make(*shaderProgram)); }
		
		/* Fields */

	   private:
		ShaderProgram* shaderProgram;
		std::unique_ptr<MeshData> meshData;

		GLuint vao;
		GLuint vbo;
		GLuint ebo;

		/* Getters and Setters */

	   public:
		inline ShaderProgram* getShaderProgram() { return this->shaderProgram; }
		inline std::size_t getVerticesLen() { return this->meshData->verticesLen; }
		inline const float* getVertices() { return this->meshData->vertices.get(); }
		inline std::size_t getElementsLen() { return this->meshData->elementsLen; }
		inline const GLuint* getElements() { return this->meshData->elements.get(); }

		/* Methods */

	   private:
		void generateGlVaoAndBuffers(); // Only to be used by MeshManager
		void cleanupForGl(); // Only to be used by MeshManager

	   public:
		void updateGlBufferData();
		void useForGl();

		/* Friends */

		friend std::unique_ptr<Mesh> std::make_unique<Mesh>(Fjordimm3DEngine::ShaderProgram*&, std::unique_ptr<Fjordimm3DEngine::MeshData>&&);

		// TODO: you don't need a mesh manager (you might want a private constructor and have a New function or something tho)

		// TODO: cleanupForGl
	};
}
