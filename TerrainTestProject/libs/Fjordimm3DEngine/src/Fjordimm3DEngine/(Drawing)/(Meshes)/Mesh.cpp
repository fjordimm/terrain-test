
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Mesh::Mesh(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData) :
		shaderProgram(shaderProgram),
		meshData(std::move(meshData)),
		vao(-1),
		vbo(-1),
		ebo(-1)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(shaderProgram != nullptr);
	}

	std::unique_ptr<Mesh> Mesh::New(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(shaderProgram != nullptr);

		std::unique_ptr<Mesh> ret = std::make_unique<Mesh>(shaderProgram, std::move(meshData));
		ret->generateGlVaoAndBuffers();
		shaderProgram->enableAttribsForMesh();
		ret->updateGlBufferData();

		return ret;
	}

	/* Methods */

	std::mutex bruhhhhhhhhhhh;

	void Mesh::generateGlVaoAndBuffers()
	{
		std::lock_guard<std::mutex> _lock(bruhhhhhhhhhhh);

		Debug::Log("...Doing thing...");
		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
		Debug::Log("...and...");
		glGenVertexArrays(1, &this->vao);
		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
		Debug::Log("vao = %u", this->vao);
		glBindVertexArray(this->vao);
		
		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

		glGenBuffers(1, &this->ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();

		// Immediately after the call of this function,
		//   someone must call ShaderProgram.enableAttribsForMesh(),
		//   and they must call Mesh.updateGlBufferData()
	}

	void Mesh::updateGlBufferData()
	{
		glBindVertexArray(this->vao);

		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

		glBufferData(GL_ARRAY_BUFFER, this->meshData->verticesLen * sizeof(this->meshData->vertices[0]), this->meshData->vertices.get(), GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->meshData->elementsLen * sizeof(this->meshData->elements[0]), this->meshData->elements.get(), GL_DYNAMIC_DRAW);

		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}

	void Mesh::useForGl()
	{
		glBindVertexArray(this->vao);
		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}

	void Mesh::cleanupForGl()
	{
		glDeleteBuffers(1, &this->ebo);
		glDeleteBuffers(1, &this->vbo);
		glDeleteVertexArrays(1, &this->vao);
		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}
}
