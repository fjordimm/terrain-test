
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(FileLoading)/FileLoading.hpp"

namespace Fjordimm3DEngine
{
	/* Constructors */

	ShaderProgram::ShaderProgram() :
		traits(),
		stride(0),
		vertexShader(-1),
		geometryShader(-1),
		fragmentShader(-1),
		formDrawContents(),
		program(-1)
	{}

	/* Methods */

	void ShaderProgram::compileAndActivate()
	{
		std::unique_ptr<std::string const> _vertexShaderSource = FileLoading::LoadFileAsText(this->getVertexShaderSourcePath());
		char const* vertexShaderSource = _vertexShaderSource->c_str();
		FJORDIMM3DENGINE_DEBUG_ASSERT(vertexShaderSource != nullptr);
		this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(this->vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(this->vertexShader);
		CheckShaderCompilation(this->vertexShader);

		std::unique_ptr<std::string const> _geometryShaderSource = FileLoading::LoadFileAsText(this->getGeometryShaderSourcePath());
		char const* geometryShaderSource = _geometryShaderSource->c_str();
		FJORDIMM3DENGINE_DEBUG_ASSERT(geometryShaderSource != nullptr);
		this->geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(this->geometryShader, 1, &geometryShaderSource, nullptr);
		glCompileShader(this->geometryShader);
		CheckShaderCompilation(this->geometryShader);

		std::unique_ptr<std::string const> _fragmentShaderSource = FileLoading::LoadFileAsText(this->getFragmentShaderSourcePath());
		char const* fragmentShaderSource = _fragmentShaderSource->c_str();
		FJORDIMM3DENGINE_DEBUG_ASSERT(fragmentShaderSource != nullptr);
		this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(this->fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(this->fragmentShader);
		CheckShaderCompilation(this->fragmentShader);

		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->geometryShader);
		glAttachShader(this->program, this->fragmentShader);

		glLinkProgram(this->program);
		glUseProgram(this->program);

		for (std::pair<std::size_t, ShaderTrait*> const& _trait : this->traits)
		{
			ShaderTrait* trait = _trait.second;
			FJORDIMM3DENGINE_DEBUG_ASSERT(trait != nullptr);

			trait->setupUniforms(this->program);
			trait->setupAttributes(this->program);
		}
	}

	void ShaderProgram::useForGl() const
	{
		glUseProgram(this->program);
	}

	void ShaderProgram::addFormDrawContent(FormDrawContent* formDrawContent)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(formDrawContent != nullptr);
		this->formDrawContents.emplace(formDrawContent);
	}

	void ShaderProgram::removeFormDrawContent(FormDrawContent* formDrawContent)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(formDrawContent != nullptr);
		this->formDrawContents.erase(formDrawContent);
	}

	void ShaderProgram::drawAllForms() const
	{
		for (FormDrawContent* formDrawContent : this->formDrawContents)
		{
			if (formDrawContent->mesh != nullptr)
			{
				formDrawContent->mesh->useForGl();

				for (std::pair<std::size_t, ShaderTrait*> const& _trait : this->traits)
				{
					ShaderTrait* trait = _trait.second;
					FJORDIMM3DENGINE_DEBUG_ASSERT(trait != nullptr);

					trait->updateUniformsFromFormDrawContent(formDrawContent);
				}

				if (formDrawContent->texture != nullptr)
				{
					formDrawContent->texture->useForGl();
				}

				glDrawElements(GL_TRIANGLES, formDrawContent->mesh->getElementsLen(), GL_UNSIGNED_INT, 0);
			}
		}
	}

	void ShaderProgram::enableAttribsForMesh()
	{
		std::size_t strideOffset = 0;
		for (std::pair<std::size_t, ShaderTrait*> const& _trait : this->traits)
		{
			ShaderTrait* trait = _trait.second;
			FJORDIMM3DENGINE_DEBUG_ASSERT(trait != nullptr);

			trait->enableAttribsForMesh(this->stride, (void*)strideOffset);
			strideOffset += trait->attribsSize();
		}
	}

	void ShaderProgram::registerTrait(ShaderTrait* trait)
	{
		FJORDIMM3DENGINE_DEBUG_ASSERT(trait != nullptr);

		this->traits[typeid(*trait).hash_code()] = trait;
		this->stride += trait->attribsSize();
	}

	void ShaderProgram::cleanupForGl()
	{
		// glDeleteShader(this->vertexShader);
		// glDeleteShader(this->geometryShader);
		// glDeleteShader(this->fragmentShader);
		// glDeleteProgram(this->program);
	}

	void ShaderProgram::CheckShaderCompilation(GLuint shader)
	{
		GLint status;
		glGetShaderiv(shader, GL_COMPILE_STATUS, &status);

		if (status)
		{ return; }
		else
		{
			static char buf[512];
			glGetShaderInfoLog(shader, 512, nullptr, buf);
			Debug::LogWarning("Shader did not compile. Output...");
			Debug::Printf("%s\n", buf);
			Debug::Exit();
		}
	}
}
