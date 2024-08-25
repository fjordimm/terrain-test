
#pragma once

#include <map>
#include <cstdlib>
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>

namespace Fjordimm3DEngine
{
	class InputManager
	{
		// TODO: make it unordered_map instead of map

		/* Structs */

	   public:
		struct InputVal
		{
		   public:
			bool isDown;
			bool pressedOnce;

			InputVal() :
				isDown(false),
				pressedOnce(false)
			{}

			InputVal(bool isDown, bool pressedOnce) :
				isDown(isDown),
				pressedOnce(pressedOnce)
			{}

			InputVal(InputVal const& that) : InputVal(that.isDown, that.pressedOnce) {}

			InputVal& operator=(InputVal const& that)
			{
				this->isDown = that.isDown;
				this->pressedOnce = that.pressedOnce;
				return *this;
			}
		};

		/* Constructors */

	   public:
		InputManager(InputManager const&) = delete;
		InputManager& operator=(InputManager const&) = delete;
		
		InputManager();
		
		/* Fields */

	   private:
		std::map<int, InputVal> keyDict;
		InputVal anyKey;
		int _anyKeyCount;

		std::map<int, InputVal> mouseButtonDict;
		InputVal anyMouseButton;
		int _anyMouseButtonCount;

		float cursorX;
		float cursorY;
		float deltaCursorX;
		float deltaCursorY;

		float deltaScrollX;
		float deltaScrollY;

		/* Getters and Setters */

	   public:
		inline InputVal const& getAnyKey() { return this->anyKey; }
		inline InputVal const& getAnyMouseButton() { return this->anyMouseButton; }
		inline float getCursorX() { return this->cursorX; }
		inline float getCursorY() { return this->cursorY; }
		inline float getDeltaCursorX() { return this->deltaCursorX; }
		inline float getDeltaCursorY() { return this->deltaCursorY; }
		inline float getDeltaScrollX() { return this->deltaScrollX; }
		inline float getDeltaScrollY() { return this->deltaScrollY; }

		/* Methods */

	   public:
		void giveWindowForGlfw(GLFWwindow* windowForGlfw);
		void nextLoopIteration();

		InputVal const& findKey(int key) const;
		InputVal const& findMouseButton(int mouseButton) const;

		/* Methods for External Use */

	   private:
		static void keyCallback(GLFWwindow* windowForGlfw, int key, int scancode, int action, int mods);
		static void mouseButtonCallback(GLFWwindow* windowForGlfw, int button, int action, int mods);
		static void cursorPosCallback(GLFWwindow* windowForGlfw, double xPos, double yPos);
		static void scrollCallback(GLFWwindow* windowForGlfw, double xOffset, double yOffset);
	};
}
