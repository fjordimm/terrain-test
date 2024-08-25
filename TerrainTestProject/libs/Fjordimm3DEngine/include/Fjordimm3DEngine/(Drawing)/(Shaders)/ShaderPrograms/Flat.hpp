
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Flat : public ShaderProgram
	{
		/* Constructors */

	   public:
		Flat(Flat const&) = delete;
		Flat& operator=(Flat const&) = delete;
		
		Flat();

		/* Fields */

	   private:
		ShaderTraits::In3DSpace traitIn3DSpace;
		ShaderTraits::Has3DShape traitHas3DShape;
		ShaderTraits::HasMaterial traitHasMaterial;
		ShaderTraits::HasTexture traitHasTexture;

		/* Methods */

		char const* getVertexShaderSourcePath() const final;
		char const* getGeometryShaderSourcePath() const final;
		char const* getFragmentShaderSourcePath() const final;
	};
}
