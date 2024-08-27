
#include "Fjordimm3DEngine/(World)/Head.hpp"

#include <cstring>
#include <chrono>
#include <cstdlib>
#include <cmath>
#include <random>
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Tran.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allMeshSamples.hpp"
#include "Fjordimm3DEngine/(Util)/(Math)/Math.hpp"
#include "Fjordimm3DEngine/(Form)/PhysicForm.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderPrograms.hpp"
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	Head::Head() :
		windowForGlfw(nullptr),
		ptrForGlfw(),
		worldState(),
		_windowWidth(-1),
		_windowHeight(-1)
	{
		Random::Reseed();
	}
	
	/* Methods */

	void Head::start(int windowWidth, int windowHeight, std::string const& windowTitle)
	{
		this->_windowWidth = windowWidth;
		this->_windowHeight = windowHeight;

		/* Create the window, initializing GLFW and GLEW */

		{
			glewExperimental = GL_TRUE;

			glfwSetErrorCallback(ErrorCallbackForGlfw);
			
			if (!glfwInit())
			{ Debug::LogFatalError("glfwInit failed."); }

			// Window hints
			glfwWindowHint(GLFW_SAMPLES, 7); // anti-aliasing

			this->windowForGlfw = glfwCreateWindow(windowWidth, windowHeight, windowTitle.c_str(), nullptr, nullptr);
			if (!this->windowForGlfw)
			{
				glfwTerminate();
				Debug::LogFatalError("glfwCreateWindow failed.");
			}

			glfwMakeContextCurrent(this->windowForGlfw);

			glewInit();
		}

		/* Bind class instances to the GLFW user pointer */

		this->ptrForGlfw.bindToGlfwWindow(this->windowForGlfw);
		this->ptrForGlfw.add<Head>(this);
		this->ptrForGlfw.add<InputManager>(&this->worldState.inputManager);

		/* OpenGL settings */

		glEnable(GL_DEPTH_TEST);
		glEnable(GL_CULL_FACE);
		glCullFace(GL_BACK);
		glEnable(GL_DITHER);
		Debug::CheckOpenGLErrors();

		/* Head settings */

		glfwSetWindowSizeCallback(this->windowForGlfw, Head::onWindowResize);

		this->worldState.inputManager.giveWindowForGlfw(this->windowForGlfw);

		/* Miscellaneous pre-main-loop tasks */

		worldState.hasCapturedCursorForCamera = false;
		glfwSetInputMode(this->windowForGlfw, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		
		if (glfwRawMouseMotionSupported())
		{ glfwSetInputMode(this->windowForGlfw, GLFW_RAW_MOUSE_MOTION, GLFW_TRUE); }
		else
		{ Debug::LogFatalError("Machine does not support raw mouse motion."); }

		this->worldState.mainCamera = Forms::Camera::New(this->worldState);
		this->worldState.mainCamera->tran.acqPosition() = Vec(0.0f, -10.0f, 0.0f);
		this->worldState.mainCamera->recalculateAndApplyViewMatrix(this->worldState);

		this->worldState.shaderProgramManager.acqFov() = Math::PiOver4;
		this->worldState.shaderProgramManager.acqAspectRatio() = (float)this->getWindowWidth() / (float)this->getWindowHeight();
		this->worldState.shaderProgramManager.acqNearClippingPlane() = 0.01f;
		this->worldState.shaderProgramManager.acqFarClippingPlane() = 100000.0f;

		Debug::CheckOpenGLErrors();

		/* Main loop */

		this->onStart();
		this->mainLoop();
	}

	void Head::mainLoop()
	{
		while (!glfwWindowShouldClose(this->windowForGlfw))
		{
			/* Stuff required by GLFW */

			glfwSwapBuffers(this->windowForGlfw);
			glfwPollEvents();
			Debug::CheckOpenGLErrors();

			/* Do movements, physics, inputs, etc. */

			float deltaTime;
			float totalTime;
			CalculateDeltaTime(deltaTime, totalTime);

			this->doCameraMovements(deltaTime);
			this->worldState.mainCamera->onUpdate(this->worldState, deltaTime);

			for (std::pair<Form* const, std::unique_ptr<Form>> const& _form : this->worldState.forms)
			{
				Form* form = _form.second.get();
				FJORDIMM3DENGINE_DEBUG_ASSERT(form != nullptr);
				
				form->onUpdate(this->worldState, deltaTime);
			}

			this->onUpdate(deltaTime);

			/* Render everything */

			glClearColor(0.1f, 0.0f, 0.25f, 1.0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			Debug::CheckOpenGLErrors();

			this->worldState.shaderProgramManager.drawEverything();

			/* Required by InputManager at the end of each iteration of the main loop */

			this->worldState.inputManager.nextLoopIteration();
		}

		this->endGlfw();
	}

	void Head::endGlfw()
	{
		glfwTerminate();
	}
	
	// TODO: store a forward vector that doesn't account for verticallness so you don't lose precision when looking straight up or down
	void Head::doCameraMovements(float deltaTime)
	{
		if (this->worldState.inputManager.getAnyMouseButton().pressedOnce)
		{
			this->worldState.hasCapturedCursorForCamera = true;
			glfwSetInputMode(this->windowForGlfw, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_ESCAPE).pressedOnce)
		{
			this->worldState.hasCapturedCursorForCamera = false;
			glfwSetInputMode(this->windowForGlfw, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		}

		this->worldState.mainCameraMovementSpeed += 0.3f * this->worldState.mainCameraMovementSpeed * this->worldState.inputManager.getDeltaScrollY();
		if (this->worldState.mainCameraMovementSpeed < 0.000002f)
		{ this->worldState.mainCameraMovementSpeed = 0.000002f; }

		float cameraMovementSpeed = this->worldState.mainCameraMovementSpeed;
		float cameraRotationSpeed = this->worldState.mainCameraRotationSpeed;

		/* Camera translation */

		Vec movement = Vecs::Zero;
		if (this->worldState.inputManager.findKey(GLFW_KEY_W).isDown)
		{
			Vec temp = glm::normalize(Vec(this->worldState.mainCamera->tran.getForwardVec().x, this->worldState.mainCamera->tran.getForwardVec().y, 0.0f));
			movement.x += temp.x;
			movement.y += temp.y;
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_S).isDown)
		{
			Vec temp = glm::normalize(Vec(this->worldState.mainCamera->tran.getForwardVec().x, this->worldState.mainCamera->tran.getForwardVec().y, 0.0f));
			movement.x -= temp.x;
			movement.y -= temp.y;
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_D).isDown)
		{
			Vec temp = glm::normalize(Vec(this->worldState.mainCamera->tran.getRightVec().x, this->worldState.mainCamera->tran.getRightVec().y, 0.0f));
			movement.x += temp.x;
			movement.y += temp.y;
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_A).isDown)
		{
			Vec temp = glm::normalize(Vec(this->worldState.mainCamera->tran.getRightVec().x, this->worldState.mainCamera->tran.getRightVec().y, 0.0f));
			movement.x -= temp.x;
			movement.y -= temp.y;
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_SPACE).isDown)
		{
			movement.z += 1.0f;
		}
		if (this->worldState.inputManager.findKey(GLFW_KEY_LEFT_SHIFT).isDown)
		{
			movement.z -= 1.0f;
		}
		if (!Vecs::RoughlyEqual(movement, Vecs::Zero))
		{
			// this->worldState.mainCamera->tran.move((cameraMovementSpeed * deltaTime) * glm::normalize(movement));
			this->worldState.mainCamera->velocity += (cameraMovementSpeed * deltaTime ) * glm::normalize(movement);
		}

		/* Camera rotation */

		if (this->worldState.hasCapturedCursorForCamera)
		{
			float deltaCursorX = this->worldState.inputManager.getDeltaCursorX();
			float deltaCursorY = this->worldState.inputManager.getDeltaCursorY();

			if (!Math::RoughlyEqual(deltaCursorX, 0.0f) || !Math::RoughlyEqual(deltaCursorY, 0.0f))
			{
				// Debug::Logf("(%f, %f)", deltaCursorX, deltaCursorY);

				glm::vec2 temp = glm::vec2(deltaCursorX, deltaCursorY);
				this->worldState.mainCamera->tran.locallyRotate(Vecs::Right, -temp.y * cameraRotationSpeed);
				this->worldState.mainCamera->tran.rotate(Vecs::Up, -temp.x * cameraRotationSpeed);
			}
		}
		{
			/* Bound camera rotation from looking beyond straight up or straight down */

			Vec eulers = this->worldState.mainCamera->tran.eulerAngles();
			static constexpr float maxAngle = Math::PiOver2 - 0.01f;
			if (eulers.x > maxAngle)
			{
				this->worldState.mainCamera->tran.locallyRotate(Vecs::Right, -(eulers.x - maxAngle));
			}
			else if (eulers.x < -maxAngle)
			{
				this->worldState.mainCamera->tran.locallyRotate(Vecs::Right, (-maxAngle - eulers.x));
			}
		}

		/* Update view matrix */

		this->worldState.mainCamera->recalculateAndApplyViewMatrix(this->worldState);
	}

	/* Functions */

	void Head::CalculateDeltaTime(float& deltaTime, float& totalTime)
	{
		using std::chrono::steady_clock;
		using std::chrono::duration;
		using durMillisecs = duration<float, std::ratio<1, 1000>>;

		static steady_clock::time_point initialTimePoint = steady_clock::now();

		static steady_clock::time_point timePoint = steady_clock::now();
		steady_clock::time_point oldTimePoint = timePoint;
		timePoint = steady_clock::now();
		durMillisecs timeElapsedSinceLastFrame = std::chrono::duration_cast<durMillisecs>(timePoint - oldTimePoint);
		deltaTime = timeElapsedSinceLastFrame.count();

		durMillisecs timeElapsedSinceStart = std::chrono::duration_cast<durMillisecs>(timePoint - initialTimePoint);
		totalTime = timeElapsedSinceStart.count();
	}

	void Head::ErrorCallbackForGlfw(int code, char const* description)
	{
		Debug::LogNonfatalError("GLFW Error with code %i: '%s'.", code, description);
	}

	/* Methods for External Use */

	void Head::onWindowResize(GLFWwindow* windowForGlfw, int width, int height)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		Head* self = PtrForGlfw::Retrieve(windowForGlfw)->get<Head>();

		self->_windowWidth = width;
		self->_windowHeight = height;

		glViewport(0, 0, width, height);
		Debug::CheckOpenGLErrors();
		self->worldState.shaderProgramManager.acqAspectRatio() = (float)width / (float)height;
	}
}
