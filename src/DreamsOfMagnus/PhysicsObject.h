#pragma once
#include "precision.h"
#include "Collisions.h"
#include "Object.h"

namespace DreamsOfMagnus {
	namespace DreamPhysics {
		class PhysicsObject : public DreamObjects::Object {
		public:
			Transform* transform;
			bool immovable;
			bool hasGravity;
			real mass;
			vector2d<real> velocity;
			DreamObjects::Collider collider;

		private:

		public:

		private:


		};
	}
	

}