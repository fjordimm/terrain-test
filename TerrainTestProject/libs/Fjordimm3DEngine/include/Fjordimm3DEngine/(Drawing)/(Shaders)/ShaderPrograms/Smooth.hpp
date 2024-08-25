
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"
#include "Fjordimm3DEngine/(headerGroups)/allShaderTraits.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class Smooth : public ShaderProgram
	{
		/* Constructors */

	   public:
		Smooth(Smooth const&) = delete;
		Smooth& operator=(Smooth const&) = delete;
		
		Smooth();

		/* Fields */

	   private:
		ShaderTraits::In3DSpace traitIn3DSpace;
		ShaderTraits::Has3DShape traitHas3DShape;
		ShaderTraits::HasNormals traitHasNormals;
		ShaderTraits::HasMaterial traitHasMaterial;
		ShaderTraits::HasTexture traitHasTexture;

		/* Methods */

		char const* getVertexShaderSourcePath() const final;
		char const* getGeometryShaderSourcePath() const final;
		char const* getFragmentShaderSourcePath() const final;
	};
}
