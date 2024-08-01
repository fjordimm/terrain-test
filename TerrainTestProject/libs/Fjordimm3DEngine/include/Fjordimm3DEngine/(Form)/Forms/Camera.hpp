
#pragma once

#include "Fjordimm3DEngine/(Form)/PhysicForm.hpp"

namespace Fjordimm3DEngine::Forms
{
	class Camera : public PhysicForm
	{
		/* Constructors */

	   protected:
		Camera() = delete;
		Camera(const Camera&) = delete;
		Camera& operator=(const Camera&) = delete;

		Camera(WorldState& worldState);

	   protected:
		template <class T, typename std::enable_if<std::is_base_of<Camera, T>::value>::type* = nullptr>
		static inline std::unique_ptr<T> New(WorldState& worldState)
		{ return PhysicForm::New<T>(worldState); }

	   public:
		static inline std::unique_ptr<Camera> New(WorldState& worldState)
		{ return Camera::New<Camera>(worldState); }

		/* Methods */

	   public:
		void recalculateAndApplyViewMatrix(WorldState& worldState);

	   protected:
		void onCreate__(WorldState& worldState) final;
		void onUpdate__(WorldState& worldState, float deltaTime) final;
		virtual void onCreate___(WorldState& worldState) {};
		virtual void onUpdate___(WorldState& worldState, float deltaTime) {};

		/* Friends */

		friend std::unique_ptr<Camera> std::make_unique<Camera>(Fjordimm3DEngine::WorldState&);
	};
}
