#pragma once
#include "precision.h"
#include "Transform.h"
#include <cstdint>
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;


namespace DreamsOfMagnus {
	namespace DreamObjects {
		static volatile uint32_t objectCounter = 0;


		class Component {
		public:

		private:

		public:

		private:
			virtual void stub() = 0;

		};

		class Object {
		public:
			const uint32_t objectID;

		private:

		public:
			Object() : objectID(incrementObjectCounter()) {}

		private:
			uint32_t incrementObjectCounter() {
				if (objectCounter == 0xffffffff) {
					objectCounter = 0;
					return 0xffffffff;
				}
				else {
					return objectCounter++;
				}
			}

		};
		

		class GameObject : public Object {
		public:
			Transform transform;
			//List<Component> components

		private:

		public:
			/*
			 * Constructors for the GameObject
			 */

			GameObject() : transform(Transform()) {}
			GameObject(const vector2d<real> position) : transform(Transform(position)) {}
			GameObject(const vector2d<real> position, real rotation) : transform(Transform(position, rotation)) {}
			GameObject(const vector2d<real> position, real rotation, const vector2d<real> scale) : transform(Transform(position, rotation, scale)) {}

			GameObject(real x, real y) : transform(Transform(x, y)) {}

			GameObject(real x, real y, real rotation) : transform(Transform(x, y, rotation)) {}

			GameObject(real x, real y, real rotation, vector2d<real> scale) : transform(Transform(x, y, rotation, scale)) {}

			GameObject(real x, real y, real rotation, real scaleX, real scaleY) : transform(Transform(x, y, rotation, scaleX, scaleY)) {}


			/*
			 * Normal Functions
			 */
			//void addComponent(Component component);
			//Component getComponent(type);
			//const List<Component> getAllComponents();
			//const List<Component> getComponents(type);

		private:
			
		};

	}



}