
#include "Fjordimm3DEngine/TerrainTest/(TerrainGeneration)/TerrainGene.hpp"

#include <cmath>
#include <random>
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"
#include "Fjordimm3DEngine/(Util)/(Math)/Math.hpp"

namespace Fjordimm3DEngine::TerrainTest
{
	/* Constructors */

	TerrainGene::TerrainGene(unsigned int seed) :
		osnRidges(),
		osnMountains()
	{
		std::default_random_engine randomEngine(seed);
		std::uniform_int_distribution<std::int64_t> randomDistr(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());

		for (std::size_t i = 0; i < osnRidges.size(); i++)
		{
			osnRidges[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}

		for (std::size_t i = 0; i < osnMountains.size(); i++)
		{
			osnMountains[i] = std::make_unique<OpenSimplexNoise>(randomDistr(randomEngine));
		}
	}

	/* Methods */

	float TerrainGene::heightAt(float x_, float y_)
	{
		float x = 1.0f * (x_ - 0.0f);
		float y = 1.0f * (y_ - 0.0f);

		float z = 0.0f;

		float ridges = 0.0f;
		{
			float ampl = 1.9f;
			float freq = 0.006f;
			for (std::size_t i = 0; i < osnRidges.size(); i++)
			{
				float val = osnRidges[i]->eval(x * freq, y * freq);
				val = -std::abs(val) + 0.25f;

				ridges += ampl * val;
				ampl *= 0.5f;
				freq *= 1.7f;
			}
		}

		float mountains = 0.0f;
		{
			float ampl = 2.1f;
			float freq = 0.003f;
			for (std::size_t i = 0; i < osnMountains.size(); i++)
			{
				mountains += ampl * osnMountains[i]->eval(x * freq, y * freq);
				ampl *= 0.5f;
				freq *= 1.7f;
			}
		}

		z = 23.2f * std::exp(ridges) * Math::Sigmoid(mountains, 0.9f, 2.7f);

		z *= 1.0f;
		return z;
	}
}
