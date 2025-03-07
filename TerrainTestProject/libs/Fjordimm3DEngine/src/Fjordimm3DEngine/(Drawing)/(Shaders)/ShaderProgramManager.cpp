
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgramManager.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	ShaderProgramManager::ShaderProgramManager() :
		shaderPrograms(),
		_mayHaveChangedProjectionMatrix(true),
		_fov(Math::PiOver4),
		_aspectRatio(1.0f),
		_nearClippingPlane(0.01f),
		_farClippingPlane(100000.0f),
		_mayHaveChangedSunRotMatrix(true),
		_sunRot(Quats::Identity),
		_mayHaveChangedSunlight(true),
		_sunBrightness(1.0f),
		_sunAmbientLight(0.0f),
		_sunColor(Colors::White)
	{}

	/* Methods */

	ShaderProgram* ShaderProgramManager::add(std::unique_ptr<ShaderProgram> shaderProgram)
	{
		ShaderProgram* ret = shaderProgram.get();
		FJORDIMM3DENGINE_DEBUG_ASSERT(ret != nullptr);
		ret->compileAndActivate();
		this->shaderPrograms.push_back(std::move(shaderProgram));

		this->_updateProjectionMatrix();

		return ret;
	}

	void ShaderProgramManager::drawEverything()
	{
		bool madeNewProjectionMatrix = false;
		if (this->_mayHaveChangedProjectionMatrix)
		{
			this->_updateProjectionMatrix();
			madeNewProjectionMatrix = true;
			this->_mayHaveChangedProjectionMatrix = false;
		}

		bool madeNewSunRotMatrix = false;
		if (this->_mayHaveChangedSunRotMatrix)
		{
			this->_updateSunRotMatrix();
			madeNewSunRotMatrix = true;
			this->_mayHaveChangedSunRotMatrix = false;
		}

		bool madeNewSunlight = false;
		if (this->_mayHaveChangedSunlight)
		{
			madeNewSunlight = true;
			this->_mayHaveChangedSunlight = false;
		}

		for (std::unique_ptr<ShaderProgram>& shaderProgram_ : this->shaderPrograms)
		{
			ShaderProgram* shaderProgram = shaderProgram_.get();
			FJORDIMM3DENGINE_DEBUG_ASSERT(shaderProgram != nullptr);

			shaderProgram->useForGl();
			
			ShaderTraits::In3DSpace* traitIn3DSpace = shaderProgram->tryGetTrait<ShaderTraits::In3DSpace>();
			if (traitIn3DSpace != nullptr)
			{
				if (madeNewProjectionMatrix)
				{
					traitIn3DSpace->setUniProj(this->_cached_projectionMatrix);
				}

				if (madeNewSunRotMatrix)
				{
					traitIn3DSpace->setUniSunRot(this->_cached_sunRotMatrix);
				}

				if (madeNewSunlight)
				{
					traitIn3DSpace->setUniSunBrightness(this->_sunBrightness);
					traitIn3DSpace->setUniSunAmbientLight(this->_sunAmbientLight);
					traitIn3DSpace->setUniSunColor(this->_sunColor.toVec());
				}
			}

			shaderProgram->drawAllForms();
		}
	}

	void ShaderProgramManager::setViewMatrix(glm::mat4 const& val)
	{
		for (std::unique_ptr<ShaderProgram>& shaderProgram_ : this->shaderPrograms)
		{
			ShaderProgram* shaderProgram = shaderProgram_.get();
			FJORDIMM3DENGINE_DEBUG_ASSERT(shaderProgram != nullptr);

			ShaderTraits::In3DSpace* traitIn3DSpace = shaderProgram->tryGetTrait<ShaderTraits::In3DSpace>();
			if (traitIn3DSpace != nullptr)
			{
				shaderProgram->useForGl();
				traitIn3DSpace->setUniView(val);
			}
		}
	}

	void ShaderProgramManager::_updateProjectionMatrix()
	{
		this->_cached_projectionMatrix = glm::perspective(this->_fov, this->_aspectRatio, this->_nearClippingPlane, this->_farClippingPlane);
	}

	void ShaderProgramManager::_updateSunRotMatrix()
	{
		this->_cached_sunRotMatrix = glm::mat4_cast(this->_sunRot);
	}
}
