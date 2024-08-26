
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include <random>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene(unsigned int seed) :
		osnDetails()
	{
		std::default_random_engine randomEngine(seed);
		std::uniform_int_distribution<std::int64_t> randomDistr(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			osnDetails[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}
	}

	/* Methods */

	float TerrainGene::heightAt(float xPre, float yPre)
	{
		double x = 3.0 * ((double)xPre - 0.0);
		double y = 3.0 * ((double)yPre - 0.0);

		double z = 0.0;

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
