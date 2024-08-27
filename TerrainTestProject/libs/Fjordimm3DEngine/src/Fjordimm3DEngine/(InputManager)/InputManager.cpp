
#include "Fjordimm3DEngine/(InputManager)/InputManager.hpp"

#include <vector>
#include "Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine
{
	using InputVal = InputManager::InputVal;

	static const InputVal FALSE_FALSE_INPUT = InputVal(false, false);

	/* Constructors */

	InputManager::InputManager() :
		keyDict(),
		anyKey(FALSE_FALSE_INPUT),
		_anyKeyCount(0),
		mouseButtonDict(),
		anyMouseButton(FALSE_FALSE_INPUT),
		_anyMouseButtonCount(0),
		cursorX(0.0f),
		cursorY(0.0f),
		deltaCursorX(0.0f),
		deltaCursorY(0.0f),
		deltaScrollX(0.0f),
		deltaScrollY(0.0f)
	{}

	/* Methods */

	void InputManager::giveWindowForGlfw(GLFWwindow* windowForGlfw)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		glfwSetKeyCallback(windowForGlfw, InputManager::keyCallback);
		glfwSetMouseButtonCallback(windowForGlfw, InputManager::mouseButtonCallback);
		glfwSetCursorPosCallback(windowForGlfw, InputManager::cursorPosCallback);
		glfwSetScrollCallback(windowForGlfw, InputManager::scrollCallback);
	}

	void InputManager::nextLoopIteration()
	{
		for (auto iter = this->keyDict.begin(); iter != this->keyDict.end(); iter++)
		{
			iter->second.pressedOnce = false;
		}

		this->anyKey.pressedOnce = false;

		for (auto iter = this->mouseButtonDict.begin(); iter != this->mouseButtonDict.end(); iter++)
		{
			iter->second.pressedOnce = false;
		}

		this->anyMouseButton.pressedOnce = false;

		this->deltaCursorX = 0.0f;
		this->deltaCursorY = 0.0f;

		this->deltaScrollX = 0.0f;
		this->deltaScrollY = 0.0f;
	}

	InputVal const& InputManager::findKey(int key) const
	{
		auto tryGet = this->keyDict.find(key);
		if (tryGet != this->keyDict.end())
		{
			return tryGet->second;
		}
		else
		{
			return FALSE_FALSE_INPUT;
		}
	}

	InputVal const& InputManager::findMouseButton(int mouseButton) const
	{
		auto tryGet = this->mouseButtonDict.find(mouseButton);
		if (tryGet != this->mouseButtonDict.end())
		{
			return tryGet->second;
		}
		else
		{
			return FALSE_FALSE_INPUT;
		}
	}

	/* Methods for External Use */

	void InputManager::keyCallback(GLFWwindow* windowForGlfw, int key, int scancode, int action, int mods)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		InputManager* self = PtrForGlfw::Retrieve(windowForGlfw)->get<InputManager>();
		FJORDIMM3DENGINE_DEBUG_ASSERT(self != nullptr);

		// only replaces the item if it doesn't exist
		auto iter = self->keyDict.emplace(key, FALSE_FALSE_INPUT).first;

		if (action == GLFW_PRESS)
		{
			if (!iter->second.isDown)
			{
				iter->second.pressedOnce = true;
				self->anyKey.pressedOnce = true;

				iter->second.isDown = true;
				self->_anyKeyCount++;
			}
		}
		else if (action == GLFW_RELEASE)
		{
			if (iter->second.isDown)
			{
				iter->second.isDown = false;
				self->_anyKeyCount--;
			}
		}

		if (self->_anyKeyCount > 0)
		{ self->anyKey.isDown = true; }
		else if (self->_anyKeyCount == 0)
		{ self->anyKey.isDown = false; }
		else
		{ Debug::LogWarning("InputManager::_anyKeyCount is below 0."); }
	}

	void InputManager::mouseButtonCallback(GLFWwindow* windowForGlfw, int button, int action, int mods)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		InputManager* self = PtrForGlfw::Retrieve(windowForGlfw)->get<InputManager>();
		FJORDIMM3DENGINE_DEBUG_ASSERT(self != nullptr);

		// only replaces the item if it doesn't exist
		auto iter = self->mouseButtonDict.emplace(button, FALSE_FALSE_INPUT).first;

		if (action == GLFW_PRESS)
		{
			if (!iter->second.isDown)
			{
				iter->second.pressedOnce = true;
				self->anyMouseButton.pressedOnce = true;

				iter->second.isDown = true;
				self->_anyMouseButtonCount++;
			}
		}
		else if (action == GLFW_RELEASE)
		{
			if (iter->second.isDown)
			{
				iter->second.isDown = false;
				self->_anyMouseButtonCount--;
			}
		}

		if (self->_anyMouseButtonCount > 0)
		{ self->anyMouseButton.isDown = true; }
		else if (self->_anyMouseButtonCount == 0)
		{ self->anyMouseButton.isDown = false; }
		else
		{ Debug::LogWarning("InputManager::_anyMouseButtonCount is below 0."); }
	}

	void InputManager::cursorPosCallback(GLFWwindow* windowForGlfw, double xPos, double yPos)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		InputManager* self = PtrForGlfw::Retrieve(windowForGlfw)->get<InputManager>();
		FJORDIMM3DENGINE_DEBUG_ASSERT(self != nullptr);

		self->deltaCursorX += xPos - self->cursorX;
		self->deltaCursorY += yPos - self->cursorY;

		self->cursorX = xPos;
		self->cursorY = yPos;
	}

	void InputManager::scrollCallback(GLFWwindow* windowForGlfw, double xOffset, double yOffset)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(windowForGlfw != nullptr);

		InputManager* self = PtrForGlfw::Retrieve(windowForGlfw)->get<InputManager>();
		FJORDIMM3DENGINE_DEBUG_ASSERT(self != nullptr);

		self->deltaScrollX += xOffset;
		self->deltaScrollY += yOffset;
	}
}
