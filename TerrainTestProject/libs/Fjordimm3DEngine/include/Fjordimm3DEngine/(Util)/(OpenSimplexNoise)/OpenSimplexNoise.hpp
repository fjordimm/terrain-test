
/*
The contents of this file were copied from https://github.com/deerel/OpenSimplexNoise.
Modifications made:
 - the namespace (from 'OpenSimplexNoise' to 'Fjordimm3DEngine')
 - the name of the class (from 'Noise' to 'OpenSimplexNoise')
 - changed double to float
 - whitespace
*/

/**
  Open Simple Noise for C++

  Port to C++ from https://gist.github.com/KdotJPG/b1270127455a94ac5d19
  by Rickard Lundberg, 2019.
*/

#pragma once

#include <cstdint>
#include <array>

namespace Fjordimm3DEngine
{
	class OpenSimplexNoise
	{
	   public:
		OpenSimplexNoise();
		OpenSimplexNoise(int64_t seed);

		//2D Open Simplex Noise.
		float eval(const float x, const float y) const;
		//3D Open Simplex Noise.
		float eval(float x, float y, float z) const;
		//4D Open Simplex Noise.
		float eval(float x, float y, float z, float w) const;

	   private:
		const float m_stretch2d;
		const float m_squish2d;
		const float m_stretch3d;
		const float m_squish3d;
		const float m_stretch4d;
		const float m_squish4d;

		const float m_norm2d;
		const float m_norm3d;
		const float m_norm4d;

		const long m_defaultSeed;

		std::array<short, 256> m_perm;
		std::array<short, 256> m_permGradIndex3d;
		std::array<char, 16> m_gradients2d;
		std::array<char, 72> m_gradients3d;
		std::array<char, 256> m_gradients4d;
		float extrapolate(int xsb, int ysb, float dx, float dy) const;
		float extrapolate(int xsb, int ysb, int zsb, float dx, float dy, float dz) const;
		float extrapolate(int xsb, int ysb, int zsb, int wsb, float dx, float dy, float dz, float dw) const;
	};
}