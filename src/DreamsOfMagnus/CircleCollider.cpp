#pragma once
#include "Collisions.h"

namespace DreamsOfMagnus {
	namespace DreamObjects {
		bool CircleCollider::isColliding(const Collider& other) {
			if (other.colliderType == circleCollider) {
				CircleCollider otherCol = (CircleCollider&)other;
				real distance = transform.position.getDistanceFromSQ(otherCol.transform.position);

				real maxDistance = radius + otherCol.radius;
				maxDistance *= maxDistance;
				if (distance <= maxDistance && distance >= -maxDistance) {
					return true;
				}
				return false;
			}
			else if (other.colliderType == rectangleCollider) {
				RectangleCollider otherCol = (RectangleCollider&)other;
				vector2d<real> direction = (otherCol.transform.position - transform.position).normalize();
				return otherCol.insideCollider(direction * radius);
			}
			else if (other.colliderType == genericCollider) {

			}
			return true;
		}

		vector2d<real> CircleCollider::collisionDirection(const Collider& other) {
			return other.transform.position - transform.position;
		}

		vector2d<real> CircleCollider::collisionDirectionNormalized(const Collider& other) {
			return (other.transform.position - transform.position).normalize();
		}

		bool CircleCollider::insideCollider(const vector2d<real> other) {
			real distance = transform.position.getDistanceFromSQ(other);
			real maxDistance = radius * radius;
			return (distance <= radius);
		}
	}
}