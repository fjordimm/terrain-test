
#include "Fjordimm3DEngine/(World)/HeadTerrainTest.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderPrograms.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allMeshSamples.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	HeadTerrainTest::HeadTerrainTest() : Head(),
		flatShaderProgram(nullptr),
		smoothShaderProgram(nullptr),
		cubeMesh(nullptr),
		sphereMesh(nullptr)
	{}

	/* Methods */

	void HeadTerrainTest::initializeShadersAndFixedMeshes()
	{
		/* Shader programs */

		flatShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Flat>());
		smoothShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Smooth>());

		/* Meshes */

		cubeMesh = this->worldState.meshManager.add(this->flatShaderProgram, MeshSamples::Cube());
		sphereMesh = this->worldState.meshManager.add(this->smoothShaderProgram, MeshSamples::Sphere<10>());
	}

	void HeadTerrainTest::onStart()
	{
		this->initializeShadersAndFixedMeshes();

		/* Sun settings */

		{
			Quat initialSunRotation = Quats::Identity;
			initialSunRotation = Quats::LocallyRotate(initialSunRotation, Vecs::Up, 0.4f);
			initialSunRotation = Quats::Rotate(initialSunRotation, Vecs::Right, 0.3f);
			this->worldState.shaderProgramManager.acqSunRot() = initialSunRotation;
			this->worldState.shaderProgramManager.acqSunBrightness() = 1.0f;
			this->worldState.shaderProgramManager.acqSunAmbientLight() = 0.2f;
			this->worldState.shaderProgramManager.acqSunColor() = Colors::White;
		}

		/* Forms */

		{
			std::unique_ptr<PhysicForm> theOrigin = PhysicForm::New(this->worldState);
			theOrigin->setMeshAndLinkToShaderProgram(this->sphereMesh);
			theOrigin->tran.acqScale() = Vec(0.3f, 0.3f, 0.3f);
			this->worldState.forms.push_back(std::move(theOrigin));
		}
	}

	void HeadTerrainTest::onUpdate(float deltaTime)
	{

	}
}
