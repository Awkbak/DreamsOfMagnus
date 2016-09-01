#pragma once
#include "Collisions.h"


namespace DreamsOfMagnus {
	namespace DreamObjects {
		/*
		* Collision Detection
		*/
		bool RectangleCollider::isColliding(const Collider& other) {
			if (other.colliderType == circleCollider) {
				CircleCollider otherCol = dynamic_cast<const CircleCollider&>(other);
				vector2d<real> direction = (otherCol.transform->position - transform->position).normalize();
				return insideCollider(direction * otherCol.radius);
			}
			else if (other.colliderType == rectangleCollider) {
				RectangleCollider otherCol = (RectangleCollider&)other;
				real xDisPos = otherCol.transform->position.X - transform->position.X;
				real yDisPos = otherCol.transform->position.Y - transform->position.Y;
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

		vector2d<real> RectangleCollider::collisionDirection(const Collider& other) {
			return other.transform->position - transform->position;
		}

		vector2d<real> RectangleCollider::collisionDirectionNormalized(const Collider& other) {
			return (other.transform->position - transform->position).normalize();
		}

		bool RectangleCollider::insideCollider(const vector2d<real> other) {
			real xDisPos = other.X - transform->position.X;
			real yDisPos = other.Y - transform->position.Y;
			if (signbit(xDisPos)) {
				xDisPos = -xDisPos;
				yDisPos = -yDisPos;
			}
			if (xDisPos > halfWidth || yDisPos > halfHeight) {
				return false;
			}
			return (xDisPos <= halfWidth && yDisPos <= halfHeight);
		}
	}
}