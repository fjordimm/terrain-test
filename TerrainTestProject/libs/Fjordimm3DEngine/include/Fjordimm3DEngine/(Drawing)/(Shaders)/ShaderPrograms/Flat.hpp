
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Flat : public ShaderProgram
	{
		/* Constructors */

	   public:
		Flat(const Flat&) = delete;
		Flat& operator=(const Flat&) = delete;
		
		Flat();

		/* Fields */

	   private:
		ShaderTraits::In3DSpace traitIn3DSpace;
		ShaderTraits::Has3DShape traitHas3DShape;
		ShaderTraits::HasTexture traitHasTexture;

		/* Methods */

		const char* getVertexShaderSourcePath() const final;
		const char* getGeometryShaderSourcePath() const final;
		const char* getFragmentShaderSourcePath() const final;
	};
}
