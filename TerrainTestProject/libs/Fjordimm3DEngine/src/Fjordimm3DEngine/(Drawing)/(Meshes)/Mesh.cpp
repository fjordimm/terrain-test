
#include "Fjordimm3DEngine/(Drawing)/(Meshes)/Mesh.hpp"

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Mesh::Mesh(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData) :
		shaderProgram(shaderProgram),
		meshData(std::move(meshData)),
		vao(-1),
		vbo(-1),
		ebo(-1)
	{}

	std::unique_ptr<Mesh> Mesh::New(ShaderProgram* shaderProgram, std::unique_ptr<MeshData> meshData)
	{
		std::unique_ptr<Mesh> ret = std::make_unique<Mesh>(shaderProgram, std::move(meshData));
		ret->generateGlVaoAndBuffers();
		shaderProgram->enableAttribsForMesh();
		ret->updateGlBufferData();

		return ret;
	}

	Mesh::~Mesh()
	{
		// this->cleanupForGl();
	}

	/* Methods */

	void Mesh::generateGlVaoAndBuffers()
	{
		glGenVertexArrays(1, &this->vao);
		glBindVertexArray(this->vao);
		
		glGenBuffers(1, &this->vbo);
		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);

		glGenBuffers(1, &this->ebo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

		// Immediately after the call of this function,
		//   someone must call ShaderProgram.enableAttribsForMesh(),
		//   and they must call Mesh.updateGlBufferData()
	}

	void Mesh::cleanupForGl()
	{
		glDeleteBuffers(1, &this->ebo);
		glDeleteBuffers(1, &this->vbo);
		glDeleteVertexArrays(1, &this->vao);
	}

	void Mesh::updateGlBufferData()
	{
		glBindVertexArray(this->vao);

		glBindBuffer(GL_ARRAY_BUFFER, this->vbo);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->ebo);

		glBufferData(GL_ARRAY_BUFFER, this->meshData->verticesLen * sizeof(this->meshData->vertices[0]), this->meshData->vertices.get(), GL_DYNAMIC_DRAW);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, this->meshData->elementsLen * sizeof(this->meshData->elements[0]), this->meshData->elements.get(), GL_DYNAMIC_DRAW);
	}

	void Mesh::useForGl()
	{
		glBindVertexArray(this->vao);
	}
}
