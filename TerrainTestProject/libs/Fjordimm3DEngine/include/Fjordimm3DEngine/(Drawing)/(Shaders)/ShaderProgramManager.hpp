
#pragma once

#include <vector>
#include <memory>
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(Util)/(Color)/Color.hpp"

namespace Fjordimm3DEngine
{
	class ShaderProgramManager
	{
		/* Constructors */

	   public:
		ShaderProgramManager(ShaderProgramManager const&) = delete;
		ShaderProgramManager& operator=(ShaderProgramManager const&) = delete;
		
		ShaderProgramManager();
		
		/* Fields */

	   private:
		std::vector<std::unique_ptr<ShaderProgram>> shaderPrograms;

		bool _mayHaveChangedProjectionMatrix;
		float _fov;
		float _aspectRatio;
		float _nearClippingPlane;
		float _farClippingPlane;
		glm::mat4 _cached_projectionMatrix;

		bool _mayHaveChangedSunRotMatrix;
		Quat _sunRot;
		glm::mat4 _cached_sunRotMatrix;

		bool _mayHaveChangedSunlight;
		float _sunBrightness;
		float _sunAmbientLight;
		Color _sunColor;

		/* Getters and Setters */

	   public:
		inline float const& getFov() const { return this->_fov; }
		inline float const& getAspectRatio() const { return this->_aspectRatio; }
		inline float const& getNearClippingPlane() const { return this->_nearClippingPlane; }
		inline float const& getFarClippingPlane() const { return this->_farClippingPlane; }
		inline float& acqFov() { this->_mayHaveChangedProjectionMatrix = true; return this->_fov; }
		inline float& acqAspectRatio() { this->_mayHaveChangedProjectionMatrix = true; return this->_aspectRatio; }
		inline float& acqNearClippingPlane() { this->_mayHaveChangedProjectionMatrix = true; return this->_nearClippingPlane; }
		inline float& acqFarClippingPlane() { this->_mayHaveChangedProjectionMatrix = true; return this->_farClippingPlane; }

		inline Quat const& getSunRot() const { return this->_sunRot; }
		inline Quat& acqSunRot() { this->_mayHaveChangedSunRotMatrix = true; return this->_sunRot; }

		inline float const& getSunBrightness() const { return this->_sunBrightness; }
		inline float const& getSunAmbientLight() const { return this->_sunAmbientLight; }
		inline Color const& getSunColor() const { return this->_sunColor; }
		inline float& acqSunBrightness() { this->_mayHaveChangedSunlight = true; return this->_sunBrightness; }
		inline float& acqSunAmbientLight() { this->_mayHaveChangedSunlight = true; return this->_sunAmbientLight; }
		inline Color& acqSunColor() { this->_mayHaveChangedSunlight = true; return this->_sunColor; }

		/* Methods */

	   public:
		ShaderProgram* add(std::unique_ptr<ShaderProgram> shaderProgram);
		void drawEverything();
		void setViewMatrix(glm::mat4 const& val);

	   private:
		void _updateProjectionMatrix();
		void _updateSunRotMatrix();
	};
}
