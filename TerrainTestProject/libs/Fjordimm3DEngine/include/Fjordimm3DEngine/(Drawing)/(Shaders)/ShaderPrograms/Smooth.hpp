
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/(Abstract)/HasNormals.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Smooth : public ShaderPrograms::HasNormals
	{
		/* Constructors */

	   public:
		Smooth(const Smooth&) = delete;
		Smooth& operator=(const Smooth&) = delete;
		
		Smooth();

		/* Methods */

		const char* getVertexShaderSourcePath() const final;
		const char* getGeometryShaderSourcePath() const final;
		const char* getFragmentShaderSourcePath() const final;
	};
}
