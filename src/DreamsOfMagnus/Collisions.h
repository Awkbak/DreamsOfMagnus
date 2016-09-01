#pragma once
#include "Vector2.h"
#include "precision.h"
#include <cstdint>
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
		
		class CircleCollider : public Collider {
		public:
			real radius;

		private:

		public:
			/*
			* Constructors
			*/
			CircleCollider() : radius(1), Collider(circleCollider, Transform()) {}
			CircleCollider(const Transform transform, const real radius) : radius(radius), Collider(circleCollider, transform) {}

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
			RectangleCollider() : width(1), halfWidth(0.5f), height(1), halfHeight(0.5f), Collider(rectangleCollider, Transform()) {}
			RectangleCollider(const Transform transform, const real squareLength) : width(squareLength), halfWidth(squareLength / 2.0f), height(squareLength), halfHeight(squareLength / 2.0f), Collider(rectangleCollider, transform) {}
			RectangleCollider(const Transform transform, const real width, const real height) : width(width), halfWidth(width / 2.0f), height(height), halfHeight(height / 2.0f), Collider(rectangleCollider, transform) {}

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