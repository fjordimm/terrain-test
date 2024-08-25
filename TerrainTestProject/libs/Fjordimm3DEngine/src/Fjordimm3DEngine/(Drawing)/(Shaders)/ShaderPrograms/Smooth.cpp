
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Smooth.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	/* Constructors */

	Smooth::Smooth() :
		traitIn3DSpace(),
		traitHas3DShape(),
		traitHasNormals(),
		traitHasMaterial(),
		traitHasTexture()
	{
		this->registerTrait(&this->traitIn3DSpace);
		this->registerTrait(&this->traitHas3DShape);
		this->registerTrait(&this->traitHasNormals);
		this->registerTrait(&this->traitHasMaterial);
		this->registerTrait(&this->traitHasTexture);
	}

	/* Methods */

	char const* Smooth::getVertexShaderSourcePath() const
	{
		return "res/shaders/Smooth/vertex.glsl";
	}

	char const* Smooth::getGeometryShaderSourcePath() const
	{
		return "res/shaders/Smooth/geometry.glsl";
	}
	
	char const* Smooth::getFragmentShaderSourcePath() const
	{
		return "res/shaders/Smooth/fragment.glsl";
	}
}
