
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Form)/PhysicForm.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainManager::TerrainManager() :
		mesh1(nullptr)
	{}

	/* Methods */

	void TerrainManager::beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram)
	{
		Debug::Log("Beginning terrain generation...");

		TerrainGene terrainGene;

		mesh1 = Mesh::New(shaderProgram, ChunkMesh(terrainGene, 500, 1.0f, 0, 0, LodTransitions::None));

		std::unique_ptr<PhysicForm> form1 = PhysicForm::New(worldState);
		form1->changeMesh(mesh1.get());
		form1->tran.acqPosition() += Vec(0.0f, 0.0f, -6.0f);
		worldState.forms.push_back(std::move(form1));
	}
}
