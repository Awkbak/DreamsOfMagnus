#pragma once

namespace DreamsOfMagnus {
	namespace DreamObjects {

		/*
		 * Base collision class
		 */
		class Collider {

		protected:
			enum ColliderType { genericCollider, circleCollider, rectangleCollider };

		public:
			//What kind of collider is this?
			ColliderType colliderType;
			Transform transform;

		public:
			/*
			 * Constructors
			 */
			Collider(ColliderType colliderType, Transform transform) : colliderType(colliderType), transform(transform) {}

			/*
			 * Collision Detection
			 */
			virtual bool isColliding(const Collider& other) = 0;

			virtual vector2d<real> collisionDirection(const Collider& other) = 0;

			virtual vector2d<real> collisionDirectionNormalized(const Collider& other) = 0;

			virtual bool insideCollider(const vector2d<real> other) = 0;


		private:

		};




	}

}