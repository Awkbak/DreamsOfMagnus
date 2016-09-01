#pragma once
#include "Collisions.h"

namespace DreamsOfMagnus {
	namespace DreamObjects {
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
			bool isColliding(const Collider& other) {
				if (other.colliderType == circleCollider) {
					CircleCollider otherCol = (CircleCollider&)other;
					vector2d<real> direction = (otherCol.transform.position - transform.position).normalize();
					return insideCollider(direction * otherCol.radius);
				}
				else if (other.colliderType == rectangleCollider) {
					RectangleCollider otherCol = (RectangleCollider&)other;
					real xDisPos = otherCol.transform.position.X - transform.position.X;
					real yDisPos = otherCol.transform.position.Y - transform.position.Y;
					if (signbit(xDisPos)) {
						xDisPos = -xDisPos;
						yDisPos = -yDisPos;
					}
					real maxXDist = halfWidth + otherCol.halfWidth;
					real maxYDist = halfHeight + otherCol.halfHeight;
					if (xDisPos > maxXDist || yDisPos > maxYDist) {
						return false;
					}
				}
				else if (other.colliderType == genericCollider) {

				}
				return true;
			}


			vector2d<real> collisionDirection(const Collider& other) {
				return other.transform.position - transform.position;
			}

			vector2d<real> collisionDirectionNormalized(const Collider& other) {
				return (other.transform.position - transform.position).normalize();
			}

			bool insideCollider(const vector2d<real> other) {
				real xDisPos = other.X - transform.position.X;
				real yDisPos = other.Y - transform.position.Y;
				if (signbit(xDisPos)) {
					xDisPos = -xDisPos;
					yDisPos = -yDisPos;
				}
				if (xDisPos > halfWidth || yDisPos > halfHeight) {
					return false;
				}
				return (xDisPos <= halfWidth && yDisPos <= halfHeight);
			}


		private:


		};
	}
}