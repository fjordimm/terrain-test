
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

#include <chrono>

namespace Fjordimm3DEngine::Random
{
	namespace _Globals
	{
		std::default_random_engine _RandomEngine(0);

		std::bernoulli_distribution _Bool;
		std::uniform_real_distribution<float> _Float0to1(0.0f, 1.0f);
	}

	void Reseed(unsigned int seed)
	{
		_Globals::_RandomEngine.seed(seed);
	}

	void Reseed()
	{
		unsigned int seed = std::chrono::time_point_cast<std::chrono::duration<unsigned int, std::micro>>(std::chrono::system_clock::now()).time_since_epoch().count();
		_Globals::_RandomEngine.seed(seed);
	}

	bool Bool()
	{
		return _Globals::_Bool(_Globals::_RandomEngine);
	}

	float Float0to1()
	{
		return _Globals::_Float0to1(_Globals::_RandomEngine);
	}

	bool From(std::bernoulli_distribution& distr)
	{ return distr(_Globals::_RandomEngine); }
}
