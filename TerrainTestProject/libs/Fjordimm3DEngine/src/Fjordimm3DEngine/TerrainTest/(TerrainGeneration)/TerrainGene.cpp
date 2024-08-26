
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include <random>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene(unsigned int seed) :
		osnRidges(),
		osnDetails()
	{
		std::default_random_engine randomEngine(seed);
		std::uniform_int_distribution<std::int64_t> randomDistr(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

		for (std::size_t i = 0; i < osnRidges.size(); i++)
		{
			osnRidges[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}

		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			osnDetails[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}
	}

	/* Methods */

	float TerrainGene::heightAt(float x_, float y_)
	{
		float x = 3.0f * (x_ - 0.0f);
		float y = 3.0f * (y_ - 0.0f);

		float z = 0.0f;

		float ampl = 3.0f;
		float freq = 0.005f;
		for (std::size_t i = 0; i < osnDetails.size(); i++)
		{
			z += ampl * osnDetails[i]->eval(x * freq, y * freq);
			ampl *= 0.5f;
			freq *= 1.7f;
		}

		z = std::exp(z);

		z *= 0.7f;
		return z;
	}
}
