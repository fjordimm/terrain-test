
#include "Fjordimm3DEngine/(Form)/Form.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Form::Form(WorldState& worldState) :
		tran(),
		formDrawContent(&this->tran, nullptr, nullptr),
		shaderProgramSpot{}
	{}

	/* Methods */

	void Form::changeMesh(Mesh* mesh)
	{
		ShaderProgram* oldShaderProgram = nullptr;
		if (this->formDrawContent.mesh != nullptr)
		{ oldShaderProgram = this->formDrawContent.mesh->getShaderProgram(); }
		
		ShaderProgram* newShaderProgram = mesh->getShaderProgram();

		if (oldShaderProgram != nullptr && oldShaderProgram != )
	}

	void Form::changeTexture(Texture* texture)
	{
		this->formDrawContent.texture = texture;
	}

	// void Form::setMeshAndLinkToShaderProgram(Mesh* mesh)
	// {
	// 	ShaderProgram* newShaderProgram = mesh->getShaderProgram();

	// 	if (this->shaderProgram != nullptr)
	// 	{
	// 		this->shaderProgram->removeForm(this->shaderProgramSpot);
	// 	}

	// 	this->shaderProgram = newShaderProgram;
	// 	if (newShaderProgram != nullptr)
	// 	{
	// 		this->shaderProgram->addForm(mesh, &this->tran);
	// 	}

	// 	this->mesh = mesh;
	// }

	void Form::onCreate(WorldState& worldState)
	{
		this->onCreate_(worldState);
	}

	void Form::onUpdate(WorldState& worldState, float deltaTime)
	{
		this->onUpdate_(worldState, deltaTime);
	}
}
