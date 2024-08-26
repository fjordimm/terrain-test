
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

			this->form->changeMesh(this->mesh.get());
		}

	/* Constructors */

	TerrainManager::TerrainManager() :
		terrainGene(),
		chunks()
	{}

	/* Methods */

	void TerrainManager::beginGeneration(WorldState& worldState, ShaderProgram* shaderProgram)
	{
		Debug::Log("Beginning terrain generation...");

		{
			PhysicForm* chunkForm = worldState.forms.add(PhysicForm::New(worldState));
			chunkForm->tran.acqPosition() = Vecs::Zero;
			
			std::unique_ptr<Chunk> chunk = std::make_unique<Chunk>(chunkForm);
			chunk->setMesh(Mesh::New(shaderProgram, ChunkMesh(terrainGene, 30, 2.0f, 0, 0, LodTransitions::None)));

			this->chunks.push_back(std::move(chunk));
		}
	}
}
