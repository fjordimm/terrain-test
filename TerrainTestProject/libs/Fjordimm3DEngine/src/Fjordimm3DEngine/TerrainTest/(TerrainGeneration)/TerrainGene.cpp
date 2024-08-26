
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene() :
		osnDetails()
	{
		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			osnDetails[i] = std::make_unique<OpenSimplexNoise>(Random::RandInt64());
		}
	}

	/* Methods */

	float TerrainGene::heightAt(float xPre, float yPre)
	{
		double x = 3.0 * ((double)xPre - 0.0);
		double y = 3.0 * ((double)yPre - 0.0);

		double z = 0.0;

		// z = osn.eval(x, y);
		double ampl = 3.0;
		double freq = 0.005;
		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			z += ampl * osnDetails[i]->eval(x * freq, y * freq);
			ampl *= 0.5;
			freq *= 1.7;
		}

		z = std::exp(z);

		z *= 0.7;
		return (float)z;
	}
}
