
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderTraits/In3DSpace.hpp"

namespace Fjordimm3DEngine::ShaderTraits
{
	/* Constructors */

	In3DSpace::In3DSpace() :
		attribPosition(-1),
		uniView(-1),
		uniProj(-1),
		uniSunRot(-1),
		uniSunBrightness(-1),
		uniSunAmbientLight(-1),
		uniSunColor(-1)
	{}

	/* Methods */

	void In3DSpace::enableAttribsForMesh(std::size_t stride)
	{
		glEnableVertexAttribArray(this->attribPosition);
		glVertexAttribPointer(this->attribPosition, 3, GL_FLOAT, GL_FALSE, stride, 0);
	}

	std::size_t In3DSpace::attribsSize()
	{
		return 3 * sizeof(float);
	}

	void In3DSpace::setupAttributes(GLuint program)
	{
		this->attribPosition = glGetAttribLocation(program, "attrib_Position");
	}

	void In3DSpace::setupUniforms(GLuint program)
	{
		this->uniView = glGetUniformLocation(program, "uni_View");
		glm::mat4 uniView_val = glm::lookAt(
			glm::vec3(0.0f, -15.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 0.0f),
			glm::vec3(0.0f, 0.0f, 1.0f)
		);
		glUniformMatrix4fv(this->uniView, 1, GL_FALSE, glm::value_ptr(uniView_val));

		this->uniProj = glGetUniformLocation(program, "uni_Proj");
		glm::mat4 uniProj_val = glm::perspective(glm::radians(45.0f), 1.0f /*aspect ratio*/, 1.0f, 100000.0f);
		glUniformMatrix4fv(this->uniProj, 1, GL_FALSE, glm::value_ptr(uniProj_val));

		this->uniSunRot = glGetUniformLocation(program, "uni_SunRot");
		glm::mat4 uniSunRot_val = glm::mat4(1.0f);
		glUniformMatrix4fv(this->uniSunRot, 1, GL_FALSE, glm::value_ptr(uniSunRot_val));

		this->uniSunBrightness = glGetUniformLocation(program, "uni_SunBrightness");
		float uniSunBrightness_val = 1.0f;
		glUniform1f(this->uniSunBrightness, uniSunBrightness_val);

		this->uniSunAmbientLight = glGetUniformLocation(program, "uni_SunAmbientLight");
		float uniSunAmbientLight_val = 0.0f;
		glUniform1f(this->uniSunAmbientLight, uniSunAmbientLight_val);

		this->uniSunColor = glGetUniformLocation(program, "uni_SunColor");
		glm::vec3 uniSunColor_val = glm::vec3(1.0f, 1.0f, 1.0f);
		glUniform3fv(this->uniSunColor, 1, glm::value_ptr(uniSunColor_val));
	}

	void In3DSpace::updateUniformsFromTran(Tran& tran) const {}

	void In3DSpace::setUniView(const glm::mat4& val) const
	{ glUniformMatrix4fv(this->uniView, 1, GL_FALSE, glm::value_ptr(val)); }

	void In3DSpace::setUniProj(const glm::mat4& val) const
	{ glUniformMatrix4fv(this->uniProj, 1, GL_FALSE, glm::value_ptr(val)); }

	void In3DSpace::setUniSunRot(const glm::mat4& val) const
	{ glUniformMatrix4fv(this->uniSunRot, 1, GL_FALSE, glm::value_ptr(val)); }
	
	void In3DSpace::setUniSunBrightness(const float& val) const
	{ glUniform1f(this->uniSunBrightness, val); }
	
	void In3DSpace::setUniSunAmbientLight(const float& val) const
	{ glUniform1f(this->uniSunAmbientLight, val); }
	
	void In3DSpace::setUniSunColor(const glm::vec3& val) const
	{ glUniform3fv(this->uniSunColor, 1, glm::value_ptr(val)); }
}
