
#pragma once

#include <list>
#include <memory>
#include "Fjordimm3DEngine/(InputManager)/InputManager.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgramManager.hpp"
#include "Fjordimm3DEngine/(Form)/FormManager.hpp"

namespace Fjordimm3DEngine
{
	// Forward declarations
	namespace Forms { class Camera; }

	class WorldState
	{
		/* Constructors */

	   public:
		WorldState(const WorldState&) = delete;
		WorldState& operator=(const WorldState&) = delete;
		
		WorldState();
		
		/* Fields */

	   public:
		InputManager inputManager;
		ShaderProgramManager shaderProgramManager;
		FormManager forms;

		bool hasCapturedCursorForCamera;
		std::unique_ptr<Forms::Camera> mainCamera;
		float mainCameraMovementSpeed;
		float mainCameraRotationSpeed;
	};
}
