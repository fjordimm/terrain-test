
#include "Fjordimm3DEngine/(Util)/(Random)/Random.hpp"

#include <chrono>
#include <limits>

namespace Fjordimm3DEngine::Random
{
	namespace _Globals
	{
		std::default_random_engine _RandomEngine(0);

		std::bernoulli_distribution _DistrBool;
		std::uniform_real_distribution<float> _DistrFloat0to1(0.0f, 1.0f);
		std::uniform_int_distribution<std::int64_t> _DistrInt64(std::numeric_limits<std::int64_t>::min(), std::numeric_limits<std::int64_t>::max());
		std::uniform_int_distribution<std::size_t> _DistrSizeT(std::numeric_limits<std::size_t>::min(), std::numeric_limits<std::size_t>::max());
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

	bool RandBool()
	{
		return _Globals::_DistrBool(_Globals::_RandomEngine);
	}

	float RandFloat0to1()
	{
		return _Globals::_DistrFloat0to1(_Globals::_RandomEngine);
	}

	std::int64_t RandInt64()
	{
		return _Globals::_DistrInt64(_Globals::_RandomEngine);
	}

	std::size_t RandSizeT()
	{
		return _Globals::_DistrSizeT(_Globals::_RandomEngine);
	}

	bool From(std::bernoulli_distribution& distr)
	{ return distr(_Globals::_RandomEngine); }
}
