
#include "Fjordimm3DEngine/(PtrForGlfw)/PtrForGlfw.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	PtrForGlfw::PtrForGlfw() :
		classMap()
	{}

	/* Methods */

	void PtrForGlfw::bindToGlfwWindow(GLFWwindow* windowForGlfw)
	{
		glfwSetWindowUserPointer(windowForGlfw, this);
	}
	
	/* Functions */
	
	PtrForGlfw* PtrForGlfw::Retrieve(GLFWwindow* windowForGlfw)
	{
		return (PtrForGlfw*)glfwGetWindowUserPointer(windowForGlfw);
	}
}
