
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

#include "Fjordimm3DEngine/(headerGroups)/allShaderPrograms.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allMeshSamples.hpp"
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainTestHead::TerrainTestHead() : Head(),
		flatShaderProgram(nullptr),
		smoothShaderProgram(nullptr),
		cubeMesh(nullptr),
		sphereMesh(nullptr),
		terrainManager()
	{}

	/* Methods */

	void TerrainTestHead::initializeShadersAndFixedMeshes()
	{
		/* Shader programs */

		flatShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Flat>());
		smoothShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Smooth>());

		/* Meshes */

		cubeMesh = Mesh::New(this->flatShaderProgram, MeshSamples::Cube());
		sphereMesh = Mesh::New(this->smoothShaderProgram, MeshSamples::Sphere<10>());
	}

	void TerrainTestHead::onStart()
	{
		this->initializeShadersAndFixedMeshes();

		/* Sun settings */

		{
			Quat initialSunRotation = Quats::Identity;
			initialSunRotation = Quats::LocallyRotate(initialSunRotation, Vecs::Up, Math::PiOver2 + 0.4f);
			initialSunRotation = Quats::Rotate(initialSunRotation, Vecs::Right, 0.3f);
			this->worldState.shaderProgramManager.acqSunRot() = initialSunRotation;
			this->worldState.shaderProgramManager.acqSunBrightness() = 1.0f;
			this->worldState.shaderProgramManager.acqSunAmbientLight() = 0.2f;
			this->worldState.shaderProgramManager.acqSunColor() = Colors::White;
		}

		/* Camera settings */

		{
			this->worldState.mainCamera->tran.acqPosition() = Vec(0.0f, -15.0f, 0.0f);
			this->worldState.shaderProgramManager.acqFov() = Math::PiOver3;
			this->worldState.mainCamera->recalculateAndApplyViewMatrix(this->worldState);

			this->worldState.mainCameraMovementSpeed = 0.0003f;
		}

		/* Other */

		{
			std::unique_ptr<PhysicForm> theOrigin = PhysicForm::New(this->worldState);
			theOrigin->changeMesh(this->sphereMesh.get());
			theOrigin->tran.acqScale() = Vec(0.1f, 0.1f, 0.1f);
			theOrigin->changeMaterialColor(Color(0.1f, 0.1f, 0.1f));
			this->worldState.forms.add(std::move(theOrigin));
		}

		// TEMP
		///////////////
		{
			std::unique_ptr<Texture> texture1 = Texture::New();
			texture1->initializeTextureForGl(0, "res/textures/star.png");

			std::unique_ptr<PhysicForm> form1 = PhysicForm::New(this->worldState);
			form1->changeMesh(this->cubeMesh.get());
			form1->changeTexture(texture1.get());
			form1->tran.acqScale() = Vec(0.5f, 0.5f, 0.5f);
			form1->tran.acqPosition() += Vec(0.0f, 0.0f, 1.5f);
			this->worldState.forms.add(std::move(form1));

			std::unique_ptr<PhysicForm> form2 = PhysicForm::New(this->worldState);
			form2->changeMesh(this->sphereMesh.get());
			form2->changeTexture(texture1.get());
			form2->tran.acqScale() = Vec(1.0f, 1.0f, 1.0f);
			form2->tran.acqPosition() += Vec(0.0f, 0.0f, 3.0f);
			this->worldState.forms.add(std::move(form2));
		}
		///////////////
		
		{
			this->terrainManager.beginGeneration(this->worldState, this->smoothShaderProgram);
		}

		Debug::Log("C");
	}

	void TerrainTestHead::onUpdate(float deltaTime)
	{

	}
}
