
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class Has3DShape : public ShaderTrait
	{
		/* Constructors */

	   public:
		Has3DShape(const Has3DShape&) = delete;
		Has3DShape& operator=(const Has3DShape&) = delete;
		
		Has3DShape();

		/* Fields */

	   private:
		GLint uniTransScale;
		GLint uniTransRot;
		GLint uniTransPos;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniTransScale(const glm::mat4& val) const;
		void setUniTransRot(const glm::mat4& val) const;
		void setUniTransPos(const glm::mat4& val) const;
	};
}
