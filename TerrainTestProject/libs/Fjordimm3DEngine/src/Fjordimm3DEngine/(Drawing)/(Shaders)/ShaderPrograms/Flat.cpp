
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/Flat.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	/* Constructors */

	Flat::Flat() :
		traitIn3DSpace(),
		traitHas3DShape(),
		traitHasMaterial(),
		traitHasTexture()
	{
		this->registerTrait(&this->traitIn3DSpace);
		this->registerTrait(&this->traitHas3DShape);
		this->registerTrait(&this->traitHasMaterial);
		this->registerTrait(&this->traitHasTexture);
	}

	/* Methods */

	char const* Flat::getVertexShaderSourcePath() const
	{
		return "res/shaders/Flat/vertex.glsl";
	}

	char const* Flat::getGeometryShaderSourcePath() const
	{
		return "res/shaders/Flat/geometry.glsl";
	}
	
	char const* Flat::getFragmentShaderSourcePath() const
	{
		return "res/shaders/Flat/fragment.glsl";
	}
}
