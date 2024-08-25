
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMesh.hpp"
#include "Fjordimm3DEngine/(Debug)/Debug.hpp"
#include "Fjordimm3DEngine/(Form)/PhysicForm.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Subclass 'Chunk' */

		/* Constructors */

		TerrainManager::Chunk::Chunk(Form* form) :
			form(form),
			mesh(nullptr)
		{}

		/* Methods */

		void TerrainManager::Chunk::setMesh(std::unique_ptr<Mesh> mesh)
		{
			this->mesh = std::move(mesh);

			this->form->changeMesh(mesh.get());
		}

	/* Constructors */

	TerrainManager::TerrainManager() :
		terrainGene()
	{}

	/* Methods */

	void TerrainManager::beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram)
	{
		Debug::Log("Beginning terrain generation...");

		{
			PhysicForm* chunkForm = worldState.forms.add(PhysicForm::New(worldState));
			
		}

		// {
		// 	this->mesh1 = Mesh::New(shaderProgram, ChunkMesh(terrainGene, 30, 2.0f, 0, 0, LodTransitions::None));

		// 	std::unique_ptr<PhysicForm> form1 = PhysicForm::New(worldState);
		// 	form1->changeMesh(this->mesh1.get());
		// 	form1->tran.acqPosition() += Vecs::Zero;
		// 	worldState.forms.add(std::move(form1));
		// }

		// {
		// 	this->mesh2 = Mesh::New(shaderProgram, ChunkMesh(terrainGene, 30, 1.0f, 2, 0, LodTransitions::Left));

		// 	std::unique_ptr<PhysicForm> form2 = PhysicForm::New(worldState);
		// 	form2->changeMesh(this->mesh2.get());
		// 	form2->tran.acqPosition() += Vecs::Zero;
		// 	worldState.forms.add(std::move(form2));
		// }
	}
}
