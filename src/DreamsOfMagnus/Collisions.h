#pragma once
#include "precision.h"
#include <irrlicht.h>
#include "Transform.h"

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace DreamsOfMagnus {
	namespace DreamObjects {

		class Collider {
		protected:
			enum ColliderType { genericCollider, circleCollider, rectangleCollider };

		public:
			//What kind of collider is this?
			ColliderType colliderType;
			Transform* transform;

		public:
			/*
			* Constructors
			*/
			Collider(ColliderType colliderType, Transform* transform) : colliderType(colliderType), transform(transform) {}

			/*
			* Collision Detection
			*/
			virtual bool isColliding(const Collider& other) = 0;

			virtual vector2d<real> collisionDirection(const Collider& other) = 0;

			virtual vector2d<real> collisionDirectionNormalized(const Collider& other) = 0;

			virtual bool insideCollider(const vector2d<real> other) = 0;


		private:

		};
		
		class CircleCollider : public Collider {
		public:
			real radius;

		private:

		public:
			/*
			* Constructors
			*/
			CircleCollider() : radius(1), Collider(circleCollider, &Transform()) {}
			CircleCollider(Transform* transform, real radius) : radius(radius), Collider(circleCollider, transform) {}
			CircleCollider(real x, real y) : radius(1), Collider(circleCollider, &Transform(x, y)) {}
			CircleCollider(real x, real y, real radius) : radius(radius), Collider(circleCollider, &Transform(x, y)) {}

			/*
			* Collision Detection
			*/
			bool isColliding(const Collider& other);


			vector2d<real> collisionDirection(const Collider& other);

			vector2d<real> collisionDirectionNormalized(const Collider& other);

			bool insideCollider(const vector2d<real> other);


		private:


		};
		
		class RectangleCollider : public Collider {

		public:
			real width;
			real height;

		private:
			real halfWidth;
			real halfHeight;

		public:
			/*
			* Constructors
			*/
			RectangleCollider() : width(1), halfWidth(0.5f), height(1), halfHeight(0.5f), Collider(rectangleCollider, &Transform()) {}
			RectangleCollider(Transform* transform, real squareLength) : width(squareLength), halfWidth(squareLength / 2.0f), height(squareLength), halfHeight(squareLength / 2.0f), Collider(rectangleCollider, transform) {}
			RectangleCollider(Transform* transform, real width, real height, real) : width(width), halfWidth(width / 2.0f), height(height), halfHeight(height / 2.0f), Collider(rectangleCollider, transform) {}
			RectangleCollider(real x, real y, real squareLength) : width(squareLength), halfWidth(squareLength / 2.0f), height(squareLength), halfHeight(squareLength / 2.0f), Collider(rectangleCollider, &Transform(x, y)) {}
			RectangleCollider(real x, real y, real width, real height) : width(width), halfWidth(width / 2.0f), height(height), halfHeight(height / 2.0f), Collider(rectangleCollider, &Transform(x, y)) {}

			/*
			* Collision Detection
			*/
			bool isColliding(const Collider& other);


			vector2d<real> collisionDirection(const Collider& other);

			vector2d<real> collisionDirectionNormalized(const Collider& other);

			bool insideCollider(const vector2d<real> other);


		private:

		};

	}
}