
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/ChunkMeshGeneration.hpp"

#include <type_traits>

namespace Fjordimm3DEngine::TerrainTest::ChunkMeshGeneration
{
	/* Enum Flags */

	LodTransitions operator|(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) | static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator&(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) & static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator^(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<LodTransitions>( static_cast<std::underlying_type_t<LodTransitions>>(lhs) ^ static_cast<std::underlying_type_t<LodTransitions>>(rhs) ); }

	LodTransitions operator~(LodTransitions the)
	{ return static_cast<LodTransitions>( ~static_cast<std::underlying_type_t<LodTransitions>>(the) ); }

	bool operator==(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<std::underlying_type_t<LodTransitions>>(lhs) == static_cast<std::underlying_type_t<LodTransitions>>(rhs); }

	bool operator!=(LodTransitions lhs, LodTransitions rhs)
	{ return static_cast<std::underlying_type_t<LodTransitions>>(lhs) != static_cast<std::underlying_type_t<LodTransitions>>(rhs); }

	/* Functions */

	std::unique_ptr<Mesh> makeMesh(TerrainGene& terrainGene, int32_t size, float chunkScale, int64_t xOff, int64_t yOff, LodTransitions lodTransitions = LodTransitions::None)
	{
		
	}
}
