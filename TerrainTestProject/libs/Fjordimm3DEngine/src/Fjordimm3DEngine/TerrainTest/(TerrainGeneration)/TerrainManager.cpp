
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainManager.hpp"

#include "Fjordimm3DEngine/(Debug)/Debug.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainManager::TerrainManager() :
		mesh1(nullptr)
	{}

	/* Methods */

	void TerrainManager::beginGeneration()
	{
		Debug::Log("Beginning terrain generation...");
	}
}
