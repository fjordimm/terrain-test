
#include "Fjordimm3DEngine/TerrainTest/TerrainTestHead.hpp"

#include "Fjordimm3DEngine/(headerGroups)/allShaderPrograms.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allMeshSamples.hpp"
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainTestHead::TerrainTestHead() : Head(),
		flatShaderProgram(nullptr),
		smoothShaderProgram(nullptr),
		cubeMesh(nullptr),
		sphereMesh(nullptr)
	{}

	/* Methods */

	void TerrainTestHead::initializeShadersAndFixedMeshes()
	{
		/* Shader programs */

		flatShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Flat>());
		// smoothShaderProgram = this->worldState.shaderProgramManager.add(std::make_unique<ShaderPrograms::Smooth>());

		/* Meshes */

		cubeMesh = this->worldState.meshManager.add(this->flatShaderProgram, MeshSamples::Cube());
		// sphereMesh = this->worldState.meshManager.add(this->smoothShaderProgram, MeshSamples::Sphere<10>());
	}

	void TerrainTestHead::onStart()
	{
		this->initializeShadersAndFixedMeshes();

		/// TEMP ///
		//////////////////////////////////////////////////////////
		std::size_t sw;
		std::size_t sh;
		std::unique_ptr<std::vector<unsigned char>> starImg = FileLoading::LoadImage("res/textures/star.png", sw, sh);

		std::size_t tw;
		std::size_t th;
		std::unique_ptr<std::vector<unsigned char>> testImg = FileLoading::LoadImage("res/textures/test.png", tw, th);

		{
			GLuint tex0;
			glGenTextures(1, &tex0);

			glActiveTexture(GL_TEXTURE0);
			glBindTexture(GL_TEXTURE_2D, tex0);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sw, sh, 0, GL_RGBA, GL_UNSIGNED_BYTE, starImg->data());

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		{
			GLuint tex1;
			glGenTextures(1, &tex1);

			glActiveTexture(GL_TEXTURE1);
			glBindTexture(GL_TEXTURE_2D, tex1);

			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tw, th, 0, GL_RGBA, GL_UNSIGNED_BYTE, testImg->data());

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
		// TODO: glGenerateMipmap()
		//////////////////////////////////////////////////////////

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

		/* Forms */

		// {
		// 	std::unique_ptr<PhysicForm> theOrigin = PhysicForm::New(this->worldState);
		// 	theOrigin->setMeshAndLinkToShaderProgram(this->sphereMesh);
		// 	theOrigin->tran.acqScale() = Vec(0.3f, 0.3f, 0.3f);
		// 	this->worldState.forms.push_back(std::move(theOrigin));
		// }

		{
			std::unique_ptr<PhysicForm> form1 = PhysicForm::New(this->worldState);
			form1->setMeshAndLinkToShaderProgram(this->cubeMesh);
			form1->tran.acqPosition() += Vec(0.0f, 0.0f, 3.0f);
			this->worldState.forms.push_back(std::move(form1));
		}
	}

	void TerrainTestHead::onUpdate(float deltaTime)
	{

	}
}
