
#pragma once

#include "Fjordimm3DEngine/(World)/Head.hpp"
#include "Fjordimm3DEngine/(Drawing)/(Shaders)/ShaderProgram.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	class TerrainTestHead : public Head
	{
		/* Constructors */

	   public:
		TerrainTestHead(const TerrainTestHead&) = delete;
		TerrainTestHead& operator=(const TerrainTestHead&) = delete;

		TerrainTestHead();
		
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
