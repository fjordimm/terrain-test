
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Flat.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	/* Constructors */

	Flat::Flat() {}

	/* Methods */

	const char* Flat::getVertexShaderSourcePath() const
	{
		return "res/shaders/Flat/vertex.glsl";
	}

	const char* Flat::getGeometryShaderSourcePath() const
	{
		return "res/shaders/Flat/geometry.glsl";
	}
	
	const char* Flat::getFragmentShaderSourcePath() const
	{
		return "res/shaders/Flat/fragment.glsl";
	}
}
