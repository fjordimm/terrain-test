
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Smooth.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	/* Constructors */

	Smooth::Smooth() :
		traitIn3DSpace(),
		traitHas3DShape(),
		traitHasNormals(),
		traitHasTexture()
	{
		this->registerTrait(&this->traitIn3DSpace);
		this->registerTrait(&this->traitHas3DShape);
		this->registerTrait(&this->traitHasNormals);
		this->registerTrait(&this->traitHasTexture);
	}

	/* Methods */

	const char* Smooth::getVertexShaderSourcePath() const
	{
		return "res/shaders/Smooth/vertex.glsl";
	}

	const char* Smooth::getGeometryShaderSourcePath() const
	{
		return "res/shaders/Smooth/geometry.glsl";
	}
	
	const char* Smooth::getFragmentShaderSourcePath() const
	{
		return "res/shaders/Smooth/fragment.glsl";
	}
}
