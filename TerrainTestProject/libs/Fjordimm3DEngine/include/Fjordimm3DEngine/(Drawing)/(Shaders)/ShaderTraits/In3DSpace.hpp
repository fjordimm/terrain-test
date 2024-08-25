
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class In3DSpace : public ShaderTrait
	{
		/* Constructors */

	   public:
		In3DSpace(In3DSpace const&) = delete;
		In3DSpace& operator=(In3DSpace const&) = delete;
		
		In3DSpace();

		/* Fields */

	   private:
		GLint attribPosition;

		GLint uniView;
		GLint uniProj;
		GLint uniSunRot;
		GLint uniSunBrightness;
		GLint uniSunAmbientLight;
		GLint uniSunColor;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride, void* strideOffset) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniView(glm::mat4 const& val) const;
		void setUniProj(glm::mat4 const& val) const;
		void setUniSunRot(glm::mat4 const& val) const;
		void setUniSunBrightness(float const& val) const;
		void setUniSunAmbientLight(float const& val) const;
		void setUniSunColor(glm::vec3 const& val) const;
	};
}
