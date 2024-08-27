
#include "Fjordimm3DEngine/(Form)/Form.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Form::Form(WorldState& worldState) :
		tran(),
		formDrawContent(&this->tran, nullptr, Colors::White, nullptr)
	{}

	Form::~Form()
	{
		ShaderProgram* oldShaderProgram = nullptr;
		if (this->formDrawContent.mesh != nullptr)
		{ oldShaderProgram = this->formDrawContent.mesh->getShaderProgram(); }

		if (oldShaderProgram != nullptr)
		{
			oldShaderProgram->removeFormDrawContent(&this->formDrawContent);
		}
	}

	/* Methods */

	void Form::changeMesh(Mesh* mesh)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(mesh != nullptr);

		ShaderProgram* oldShaderProgram = nullptr;
		if (this->formDrawContent.mesh != nullptr)
		{ oldShaderProgram = this->formDrawContent.mesh->getShaderProgram(); }

		ShaderProgram* newShaderProgram = mesh->getShaderProgram();
		FJORDIMM3DENGINE_DEBUG_ASSERT(newShaderProgram != nullptr);

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

	void Form::changeMaterialColor(Color materialColor)
	{
		this->formDrawContent.materialColor = materialColor;
	}

	void Form::changeTexture(Texture* texture)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(texture != nullptr);
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
