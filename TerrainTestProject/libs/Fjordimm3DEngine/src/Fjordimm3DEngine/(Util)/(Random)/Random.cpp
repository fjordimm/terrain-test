
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

#include <chrono>

namespace Fjordimm3DEngine::Random
{
	namespace _Globals
	{
		std::default_random_engine _RandomEngine(0);

		std::bernoulli_distribution _DistrBernoulli;
	}

	void Reseed(unsigned long long seed)
	{
		_Globals::_RandomEngine.seed(seed);
	}

	void Reseed()
	{
		unsigned long long seed = std::chrono::time_point_cast<std::chrono::duration<unsigned long long, std::micro>>(std::chrono::system_clock::now()).time_since_epoch().count();
		_Globals::_RandomEngine.seed(seed);
	}

	bool FromBernoulli()
	{
		return _Globals::_DistrBernoulli(_Globals::_RandomEngine);
	}

	bool From(std::bernoulli_distribution& distr)
	{ return distr(_Globals::_RandomEngine); }
}
