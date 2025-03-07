
#pragma once

#include <string>
#include <list>
#include <memory>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.hpp"
#include "Fjordimm3DEngine/(World)/WorldState.hpp"
#include "Fjordimm3DEngine/(Form)/Form.hpp"
#include "Fjordimm3DEngine/(Form)/Forms/Camera.hpp"

namespace Fjordimm3DEngine
{
	class Head
	{
		/* Constructors */

	   public:
		Head(Head const&) = delete;
		Head& operator=(Head const&) = delete;

		Head();

		/* Fields */

	   protected:
		GLFWwindow* windowForGlfw;
		PtrForGlfw ptrForGlfw;
		WorldState worldState;

		int _windowWidth;
		int _windowHeight;

		/* Getters and Setters */

	   protected:
		inline int const& getWindowWidth() { return this->_windowWidth; }
		inline int const& getWindowHeight() { return this->_windowHeight; }

		/* Methods */

	   public:
		void start(int windowWidth = 600, int windowHeight = 600, std::string const& windowTitle = "Placeholder Window Title");
	
	   protected:
		void mainLoop();
		void endGlfw();
		void doCameraMovements(float deltaTime);

		virtual void onStart() = 0;
		virtual void onUpdate(float deltaTime) = 0;
		virtual void onFinish() = 0;

		/* Functions */

	   protected:
		static void CalculateDeltaTime(float& deltaTime, float& totalTime); // In milliseconds
		static void ErrorCallbackForGlfw(int code, char const* description);

		/* Methods for External Use */

	   private:
		static void onWindowResize(GLFWwindow* windowForGlfw, int width, int height);
	};
}
