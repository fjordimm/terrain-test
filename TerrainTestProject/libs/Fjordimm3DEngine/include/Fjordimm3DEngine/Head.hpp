
#pragma once

#include <string>
#include <list>
#include <memory>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.hpp"
#include "Fjordimm3DEngine/WorldState.hpp"
#include "Fjordimm3DEngine/(Form)/Form.hpp"
#include "Fjordimm3DEngine/(Form)/Forms/Camera.hpp"

namespace Fjordimm3DEngine
{
	class Head
	{
		/* Constructors */

	   public:
		Head(const Head&) = delete;
		Head& operator=(const Head&) = delete;

		Head();

		/* Fields */

	   private:
		GLFWwindow* windowForGlfw;
		PtrForGlfw ptrForGlfw;
		WorldState worldState;

		int _windowWidth;
		int _windowHeight;

		/* Getters & Setters */

	   private:
		inline const int& getWindowWidth() { return this->_windowWidth; }
		inline const int& getWindowHeight() { return this->_windowHeight; }

		/* Methods */

	   public:
		void start(int windowWidth = 600, int windowHeight = 600, const std::string windowTitle = "Placeholder Window Title");
	
	   private:
		void mainLoop();
		void endGlfw();
		void doCameraMovements(float deltaTime);

		void onStart();
		void onUpdate(float deltaTime);

		/* Functions */

	   private:
		static void CalculateDeltaTime(float& deltaTime, float& totalTime); // In milliseconds

		/* Methods for External Use */

	   private:
		static void onWindowResize(GLFWwindow* windowForGlfw, int width, int height);
	};
}
