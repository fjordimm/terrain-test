
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Smooth : public ShaderProgram
	{
		/* Constructors */

	   public:
		Smooth(const Smooth&) = delete;
		Smooth& operator=(const Smooth&) = delete;
		
		Smooth();

		/* Fields */

	   private:
		ShaderTraits::In3DSpace traitIn3DSpace;
		ShaderTraits::Has3DShape traitHas3DShape;
		ShaderTraits::HasNormals traitHasNormals;

		/* Methods */

		const char* getVertexShaderSourcePath() const final;
		const char* getGeometryShaderSourcePath() const final;
		const char* getFragmentShaderSourcePath() const final;
	};
}
