
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
		program(-1),
		trans()
	{}

	/* Methods */

	void ShaderProgram::compileAndActivate()
	{
		std::unique_ptr<const std::string> _vertexShaderSource = FileLoading::LoadFileAsText(this->getVertexShaderSourcePath());
		const char* vertexShaderSource = _vertexShaderSource->c_str();
		this->vertexShader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(this->vertexShader, 1, &vertexShaderSource, nullptr);
		glCompileShader(this->vertexShader);
		checkShaderCompilation(this->vertexShader);

		std::unique_ptr<const std::string> _geometryShaderSource = FileLoading::LoadFileAsText(this->getGeometryShaderSourcePath());
		const char* geometryShaderSource = _geometryShaderSource->c_str();
		this->geometryShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(this->geometryShader, 1, &geometryShaderSource, nullptr);
		glCompileShader(this->geometryShader);
		checkShaderCompilation(this->geometryShader);

		std::unique_ptr<const std::string> _fragmentShaderSource = FileLoading::LoadFileAsText(this->getFragmentShaderSourcePath());
		const char* fragmentShaderSource = _fragmentShaderSource->c_str();
		this->fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(this->fragmentShader, 1, &fragmentShaderSource, nullptr);
		glCompileShader(this->fragmentShader);
		checkShaderCompilation(this->fragmentShader);

		this->program = glCreateProgram();
		glAttachShader(this->program, this->vertexShader);
		glAttachShader(this->program, this->geometryShader);
		glAttachShader(this->program, this->fragmentShader);

		glLinkProgram(this->program);
		glUseProgram(this->program);

		for (ShaderTrait* trait : this->traits)
		{
			trait->setupUniforms(this->program);
			trait->setupAttributes(this->program);
		}
	}

	void ShaderProgram::use() const
	{
		glUseProgram(this->program);
	}

	std::list<std::tuple<Mesh*, Tran*>>::const_iterator ShaderProgram::addForm(Mesh* mesh, Tran* tran)
	{
		this->trans.push_back(std::make_tuple(mesh, tran));
		return this->trans.end();
	}

	void ShaderProgram::removeForm(const std::list<std::tuple<Mesh*, Tran*>>::const_iterator& iter)
	{
		this->trans.erase(iter);
	}

	void ShaderProgram::drawAllTrans() const
	{
		for (const std::tuple<Mesh*, Tran*>& _tup : this->trans)
		{
			Mesh* mesh = std::get<0>(_tup);
			Tran* tran = std::get<1>(_tup);

			if (mesh != nullptr)
			{
				glBindVertexArray(mesh->getVaoForDrawing());

				for (ShaderTrait* trait : this->traits)
				{
					trait->updateUniformsFromTran(*tran);
				}
				glDrawElements(GL_TRIANGLES, mesh->getElementsLen(), GL_UNSIGNED_INT, 0);
			}
		}
	}

	void ShaderProgram::enableAttribsForMesh()
	{
		for (ShaderTrait* trait : this->traits)
		{
			trait->enableAttribsForMesh(this->stride);
		}
	}

	void ShaderProgram::registerTrait(ShaderTrait* trait)
	{
		this->traits.push_back(trait);
		this->stride += trait->attribsSize();
	}

	void ShaderProgram::checkShaderCompilation(GLuint shader) const
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
