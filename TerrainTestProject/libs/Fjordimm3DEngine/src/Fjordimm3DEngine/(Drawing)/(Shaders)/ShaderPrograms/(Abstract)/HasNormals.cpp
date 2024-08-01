
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/(Abstract)/HasNormals.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	/* Constructors */

	HasNormals::HasNormals() :
		attribNormal(-1)
	{}

	/* Methods */

	MeshVertAttribs HasNormals::attribFlagsForMeshSamples__() const
	{
		return MeshVertAttribs::Normals3D | this->attribFlagsForMeshSamples___();
	}

	void HasNormals::enableAttribsForMesh__()
	{
		glEnableVertexAttribArray(this->attribNormal);
		glVertexAttribPointer(this->attribNormal, 3, GL_FLOAT, GL_FALSE, this->getStride(), (void*)(this->getStride() - 3 * sizeof(float)));

		this->enableAttribsForMesh___();
	}

	std::size_t HasNormals::getStride__()
	{
		return 3 * sizeof(float) + this->getStride___();
	}

	void HasNormals::setupUniforms__()
	{
		this->setupUniforms___();
	}

	void HasNormals::setupAttributes__()
	{
		this->attribNormal = glGetAttribLocation(this->program, "attrib_Normal");

		this->setupAttributes___();
	}

	void HasNormals::updateUniformsFromTran__(Tran& tran) const
	{
		this->updateUniformsFromTran___(tran);
	}
}
