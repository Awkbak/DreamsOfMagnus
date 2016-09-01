#pragma once
#include "Vector2.h"
#include "precision.h"
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
			vector2d<real> position;
			real rotation;
			vector2d<real> scale;

		private:

		public:
			/*
			 * Constructors for the GameObject
			 */

			GameObject() : position(vector2d<real>()), rotation(0), scale(vector2d<real>()) {}
			GameObject(const vector2d<real> position) : position(position), rotation(0), scale(vector2d<real>()){}
			GameObject(const vector2d<real> position, const real rotation) : position(position), rotation(rotation), scale(vector2d<real>()) {}
			GameObject(const vector2d<real> position, const real rotation, const vector2d<real> scale) : position(position), rotation(rotation), scale(scale) {}

			GameObject(const real x, const real y) : position(vector2d<real>(x, y)), rotation(0), scale(vector2d<real>()) {}

			GameObject(const real x, const real y, const real rotation) : position(vector2d<real>(x, y)), rotation(rotation), scale(vector2d<real>()) {}

			GameObject(const real x, const real y, const real rotation, const vector2d<real> scale) : position(vector2d<real>(x, y)), rotation(rotation), scale(scale) {}

			GameObject(const real x, const real y, const real rotation, const real scaleX, const real scaleY) : position(vector2d<real>(x, y)), rotation(rotation), scale(vector2d<real>(scaleX, scaleY)) {}

		private:
			
		};

	}



}