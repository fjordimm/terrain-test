
#include "Fjordimm3DEngine/(World)/WorldState.hpp"

#include "Fjordimm3DEngine/(Form)/Form.hpp"
#include "Fjordimm3DEngine/(Form)/Forms/Camera.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	WorldState::WorldState() :
		inputManager(),
		shaderProgramManager(),
		forms(),
		hasCapturedCursorForCamera(false),
		mainCamera(nullptr),
		mainCameraMovementSpeed(0.0001f),
		mainCameraRotationSpeed(0.0025f)
	{}
}
