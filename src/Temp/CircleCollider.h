#pragma once


using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace DreamsOfMagnus {
	namespace DreamObjects {
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
			bool isColliding(const Collider& other) {
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


			vector2d<real> collisionDirection(const Collider& other) {
				return other.transform.position - transform.position;
			}

			vector2d<real> collisionDirectionNormalized(const Collider& other) {
				return (other.transform.position - transform.position).normalize();
			}

			bool insideCollider(const vector2d<real> other) {
				real distance = transform.position.getDistanceFromSQ(other);
				real maxDistance = radius * radius;
				return (distance <= radius);
			}


		private:


		};
	}
}