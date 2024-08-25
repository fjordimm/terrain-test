
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene()
	{}

	/* Methods */

	float TerrainGene::heightAt(float xPre, float yPre)
	{
		double x = 0.2 * ((double)xPre - 0.0);
		double y = 0.2 * ((double)yPre - 0.0);

		double z = 0.0;

		z = std::sin(x) + std::sin(y);

		z *= 1.0;
		return (float)z;
	}
}
