
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
		FJORDIMM3DENGINE_DEBUG_ASSERT(mesh);

		ShaderProgram* oldShaderProgram = nullptr;
		if (this->formDrawContent.mesh != nullptr)
		{ oldShaderProgram = this->formDrawContent.mesh->getShaderProgram(); }
		
		ShaderProgram* newShaderProgram = mesh->getShaderProgram();

		if (oldShaderProgram != newShaderProgram)
		{
			if (oldShaderProgram != nullptr)
			{
				oldShaderProgram->removeFormDrawContent(&this->formDrawContent);
			}

			newShaderProgram->addFormDrawContent(&this->formDrawContent);
		}

		this->formDrawContent.mesh = mesh;
	}

	void Form::changeTexture(Texture* texture)
	{
		this->formDrawContent.texture = texture;
	}

	void Form::onCreate(WorldState& worldState)
	{
		this->onCreate_(worldState);
	}

	void Form::onUpdate(WorldState& worldState, float deltaTime)
	{
		this->onUpdate_(worldState, deltaTime);
	}
}
