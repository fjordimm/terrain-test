
#pragma once

#include <random>

namespace Fjordimm3DEngine::Random
{
	namespace _Globals
	{
		extern std::default_random_engine _RandomEngine;

		extern std::bernoulli_distribution _DistrBernoulli;
	}

	void Reseed(unsigned long long seed);
	void Reseed();

	bool FromBernoulli();

	template <typename T>
	T From(std::uniform_int_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::uniform_real_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	bool From(std::bernoulli_distribution& distr);

	template <typename T>
	T From(std::binomial_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::geometric_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::negative_binomial_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::poisson_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::exponential_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::gamma_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::weibull_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::extreme_value_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::normal_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::lognormal_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::chi_squared_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::cauchy_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::fisher_f_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::student_t_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::discrete_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::piecewise_constant_distribution	<T>& distr)
	{ return distr(_Globals::_RandomEngine); }

	template <typename T>
	T From(std::piecewise_linear_distribution<T>& distr)
	{ return distr(_Globals::_RandomEngine); }
}
