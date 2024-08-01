
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderPrograms/(Abstract)/ThreeDShape.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class HasNormals : public ShaderPrograms::ThreeDShape
	{
		/* Constructors */

	   public:
		HasNormals(const HasNormals&) = delete;
		HasNormals& operator=(const HasNormals&) = delete;
		
		HasNormals();
		
		/* Fields */

	   private:
		GLint attribNormal;

		/* Methods */

	   protected:
		MeshVertAttribs attribFlagsForMeshSamples__() const final;
		void enableAttribsForMesh__() final;
	   	std::size_t getStride__() final;
		void setupUniforms__() final;
		void setupAttributes__() final;
		void updateUniformsFromTran__(Tran& tran) const final;

	   protected:
		virtual MeshVertAttribs attribFlagsForMeshSamples___() const { return MeshVertAttribs::None; };
		virtual void enableAttribsForMesh___() {}
		virtual std::size_t getStride___() { return 0; }
		virtual void setupUniforms___() {}
		virtual void setupAttributes___() {}
		virtual void updateUniformsFromTran___(Tran& tran) const {}
	};
}
