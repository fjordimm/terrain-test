
#include "Fjordimm3DEngine/(World)/WorldState.hpp"

#include "Fjordimm3DEngine/(Form)/Form.hpp"
#include "Fjordimm3DEngine/(Form)/Forms/Camera.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	WorldState::WorldState() :
		inputManager(),
		shaderProgramManager(),
		meshManager(),
		forms(),
		hasCapturedCursorForCamera(false),
		mainCamera(nullptr),
		mainCameraMovementSpeed(0.001f),
		mainCameraRotationSpeed(0.0025f)
	{}
}
