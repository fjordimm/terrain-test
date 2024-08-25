
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTrait.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	class Has3DShape : public ShaderTrait
	{
		/* Constructors */

	   public:
		Has3DShape(Has3DShape const&) = delete;
		Has3DShape& operator=(Has3DShape const&) = delete;
		
		Has3DShape();

		/* Fields */

	   private:
		GLint uniTransScale;
		GLint uniTransRot;
		GLint uniTransPos;

		/* Methods */

	   public:
		void enableAttribsForMesh(std::size_t stride, void* strideOffset) final;
		std::size_t attribsSize() final;
		void setupAttributes(GLuint program) final;
		void setupUniforms(GLuint program) final;
		void updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const final;

		void setUniTransScale(glm::mat4 const& val) const;
		void setUniTransRot(glm::mat4 const& val) const;
		void setUniTransPos(glm::mat4 const& val) const;
	};
}
