
#pragma once

#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine::ShaderPrograms
{
	class InSpace : public ShaderProgram
	{
		/* Constructors */

	   public:
		InSpace(const InSpace&) = delete;
		InSpace& operator=(const InSpace&) = delete;
		
		InSpace();
		
		/* Fields */

	   private:
		GLint attribPosition;

		GLint uniView;
		GLint uniProj;
		GLint uniSunRot;
		GLint uniSunBrightness;
		GLint uniSunAmbientLight;
		GLint uniSunColor;

		/* Getters & Setters */

	   public:
		void setUniView(const glm::mat4& val) const;
		void setUniProj(const glm::mat4& val) const;
		void setUniSunRot(const glm::mat4& val) const;
		void setUniSunBrightness(const float& val) const;
		void setUniSunAmbientLight(const float& val) const;
		void setUniSunColor(const glm::vec3& val) const;

		/* Methods */

	   public:
		MeshVertAttribs attribFlagsForMeshSamples() const final;
		void enableAttribsForMesh() final;
	   protected:
	   	std::size_t getStride() final;
		void setupUniforms() final;
		void setupAttributes() final;
		void updateUniformsFromTran(Tran& tran) const final;

	   protected:
		virtual MeshVertAttribs attribFlagsForMeshSamples_() const { return MeshVertAttribs::None; };
		virtual void enableAttribsForMesh_() {}
		virtual std::size_t getStride_() { return 0; }
		virtual void setupUniforms_() {}
		virtual void setupAttributes_() {}
		virtual void updateUniformsFromTran_(Tran& tran) const {}
	};
}
