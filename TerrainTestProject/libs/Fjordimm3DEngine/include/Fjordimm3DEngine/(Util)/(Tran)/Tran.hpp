
#pragma once

#include <string>
#include "Fjordimm3DEngine/(headerGroups)/glmGroup.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Vec.hpp"
#include "Fjordimm3DEngine/(Util)/(Tran)/Quat.hpp"

namespace Fjordimm3DEngine
{
	class Tran
	{
		/* Constructors */

	   public:
		Tran();
		Tran(Tran const& that);
		Tran& operator=(Tran const& that);

		/* Fields */

	   private:
		bool _mayHaveChangedPosition;
		Vec _position;
		glm::mat4 _cached_positionMatrix;

		bool _mayHaveChangedRotation;
		Quat _rotation;
		glm::mat4 _cached_rotationMatrix;
		Vec _cached_forwardVec;
		Vec _cached_upVec;
		Vec _cached_rightVec;

		bool _mayHaveChangedScale;
		Vec _scale;
		glm::mat4 _cached_scaleMatrix;

		/* Getters and Setters */

	   public:
		inline Vec const& getPosition() const { return this->_position; }
		inline Quat const& getRotation() const { return this->_rotation; }
		inline Vec const& getScale() const { return this->_scale; }
		inline Vec& acqPosition() { this->_mayHaveChangedPosition = true; return this->_position; }
		inline Quat& acqRotation() { this->_mayHaveChangedRotation = true; return this->_rotation; }
		inline Vec& acqScale() { this->_mayHaveChangedScale = true; return this->_scale; }
		
		glm::mat4 const& getPositionMatrix();
		glm::mat4 const& getRotationMatrix();
		Vec const& getForwardVec();
		Vec const& getUpVec();
		Vec const& getRightVec();
		const glm::mat4 getScaleMatrix();

		/* Methods */

	   public:
		std::string toString() const;
		Vec eulerAngles() const;

		void move(Vec const& translation);
		void locallyMove(Vec const& translation);
		void moveAlong(Vec const& axis, float distance);
		void locallyMoveAlong(Vec const& axis, float distance);
		void rotate(Vec const& axis, float radians);
		void locallyRotate(Vec const& axis, float radians);
		void lookTowards(Vec const& target, Vec const& up = Vecs::Up);
		
	   private:
		void _updatePositionDeps();
		void _updateRotationDeps();
		void _updateScaleDeps();
	};
}
