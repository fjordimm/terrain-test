
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"

#include <sstream>
#include <cmath>

namespace Fjordimm3DEngine::Vecs
{
	std::string ToString(Vec const& subj)
	{
		std::ostringstream ret;
		ret << "(" << subj.x << ", " << subj.y << ", " << subj.z << ")";
		return ret.str();
	}

	bool RoughlyEqual(Vec const& a, Vec const& b, float epsilon)
	{
		return
			(std::abs(a.x - b.x) < epsilon)
			&& (std::abs(a.y - b.y) < epsilon)
			&& (std::abs(a.z - b.z) < epsilon);
	}
}
