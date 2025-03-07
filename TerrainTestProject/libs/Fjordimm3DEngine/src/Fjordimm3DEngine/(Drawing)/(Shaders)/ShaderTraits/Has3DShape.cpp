
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/Has3DShape.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	Has3DShape::Has3DShape() :
		uniTransScale(-1),
		uniTransRot(-1),
		uniTransPos(-1)
	{}

	/* Methods */

	void Has3DShape::enableAttribsForMesh(std::size_t stride, void* strideOffset)
	{}

	std::size_t Has3DShape::attribsSize()
	{ return 0; }

	void Has3DShape::setupAttributes(GLuint program)
	{}

	void Has3DShape::setupUniforms(GLuint program)
	{
		this->uniTransScale = glGetUniformLocation(program, "uni_TransScale");
		glm::mat4 uniTransScale_val = glm::mat4(1.0f);
		glUniformMatrix4fv(this->uniTransScale, 1, GL_FALSE, glm::value_ptr(uniTransScale_val));

		this->uniTransRot = glGetUniformLocation(program, "uni_TransRot");
		glm::mat4 uniTransRot_val = glm::mat4(1.0f);
		glUniformMatrix4fv(this->uniTransRot, 1, GL_FALSE, glm::value_ptr(uniTransRot_val));
		
		this->uniTransPos = glGetUniformLocation(program, "uni_TransPos");
		glm::mat4 uniTransPos_val = glm::mat4(1.0f);
		glUniformMatrix4fv(this->uniTransPos, 1, GL_FALSE, glm::value_ptr(uniTransPos_val));

		FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR();
	}
	
	void Has3DShape::updateUniformsFromFormDrawContent(FormDrawContent* formDrawContent) const
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(formDrawContent != nullptr);

		this->setUniTransScale(formDrawContent->tran->getScaleMatrix());
		this->setUniTransRot(formDrawContent->tran->getRotationMatrix());
		this->setUniTransPos(formDrawContent->tran->getPositionMatrix());
	}

	void Has3DShape::setUniTransScale(glm::mat4 const& val) const
	{ glUniformMatrix4fv(this->uniTransScale, 1, GL_FALSE, glm::value_ptr(val)); FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR(); }

	void Has3DShape::setUniTransRot(glm::mat4 const& val) const
	{ glUniformMatrix4fv(this->uniTransRot, 1, GL_FALSE, glm::value_ptr(val)); FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR(); }

	void Has3DShape::setUniTransPos(glm::mat4 const& val) const
	{ glUniformMatrix4fv(this->uniTransPos, 1, GL_FALSE, glm::value_ptr(val)); FJORDIMM3DENGINE_DEBUG_ASSERT_GL_ERROR(); }
}
