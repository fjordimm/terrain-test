
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/(Abstract)/ThreeDShape.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Flat : public ShaderPrograms::ThreeDShape
	{
		/* Constructors */

	   public:
		Flat(const Flat&) = delete;
		Flat& operator=(const Flat&) = delete;
		
		Flat();

		/* Methods */

		const char* getVertexShaderSourcePath() const final;
		const char* getGeometryShaderSourcePath() const final;
		const char* getFragmentShaderSourcePath() const final;
	};
}
