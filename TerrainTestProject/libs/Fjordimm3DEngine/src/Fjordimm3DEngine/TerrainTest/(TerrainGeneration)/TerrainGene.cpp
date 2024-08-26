
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene() :
		osn(Random::RandInt64())
	{}

	/* Methods */

	float TerrainGene::heightAt(float xPre, float yPre)
	{
		double x = 0.11 * ((double)xPre - 19.242378237);
		double y = 0.14 * ((double)yPre - 0.0);

		double z = 0.0;

		z = osn.eval(x, y);

		z *= 5.0;
		return (float)z;
	}
}
