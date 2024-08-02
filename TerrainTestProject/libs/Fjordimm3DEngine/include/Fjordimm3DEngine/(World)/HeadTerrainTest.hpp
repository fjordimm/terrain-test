
#pragma once

#include "Fjordimm3DEngine/(World)/Head.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine
{
	class HeadTerrainTest : public Head
	{
		/* Constructors */

	   public:
		HeadTerrainTest(const HeadTerrainTest&) = delete;
		HeadTerrainTest& operator=(const HeadTerrainTest&) = delete;

		HeadTerrainTest();
		
		/* Fields */

	   private:
		ShaderProgram* flatShaderProgram;
		ShaderProgram* smoothShaderProgram;
		Mesh* cubeMesh;
		Mesh* sphereMesh;

		/* Methods */

	   private:
		void initializeShadersAndFixedMeshes();

	   protected:
		void onStart() final;
		void onUpdate(float deltaTime) final;
	};
}
