
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class In3DSpace : public ShaderTrait
	{
		/* Constructors */

	   public:
		In3DSpace(const In3DSpace&) = delete;
		In3DSpace& operator=(const In3DSpace&) = delete;
		
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
		void enableAttribsForMesh(std::size_t stride) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniView(const glm::mat4& val) const;
		void setUniProj(const glm::mat4& val) const;
		void setUniSunRot(const glm::mat4& val) const;
		void setUniSunBrightness(const float& val) const;
		void setUniSunAmbientLight(const float& val) const;
		void setUniSunColor(const glm::vec3& val) const;
	};
}
