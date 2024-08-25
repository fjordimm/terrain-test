
#include "Fjordimm3DEngine/(Util)/(Tran)/Quat.hpp"

namespace Fjordimm3DEngine::Quats
{
	Quat Rotate(Quat const& quat, Vec const& axis, float radians)
	{
		return glm::angleAxis(radians, axis) * quat;
	}

	Quat LocallyRotate(Quat const& quat, Vec const& axis, float radians)
	{
		return quat * glm::angleAxis(radians, axis);
	}

	Quat LookTowards(Vec const& position, Vec const& target, Vec const& up)
	{
		Vec newForwards = glm::normalize(target - position);

		Vec xAxis = glm::normalize(glm::cross(newForwards, up));
		Vec yAxis = newForwards;
		Vec zAxis = glm::normalize(glm::cross(xAxis, newForwards));
		glm::mat3 rotationMatrix = glm::mat3(xAxis, yAxis, zAxis);

		return glm::quat_cast(rotationMatrix);
	}
}
