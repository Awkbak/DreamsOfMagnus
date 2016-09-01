#pragma once
#include "precision.h"
#include <irrlicht.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;

namespace DreamsOfMagnus {
	class Transform {
	public:
		vector2d<real> position;
		real rotation;
		vector2d<real> scale;

	private:

	public:
		/*
		* Constructors
		*/
		Transform() : position(vector2d<real>()), rotation(0), scale(vector2d<real>()) {}
		Transform(const vector2d<real> position) : position(position), rotation(0), scale(vector2d<real>()) {}
		Transform(const vector2d<real> position, const real rotation) : position(position), rotation(rotation), scale(vector2d<real>()) {}
		Transform(const vector2d<real> position, const real rotation, const vector2d<real> scale) : position(position), rotation(rotation), scale(scale) {}

		Transform(const real x, const real y) : position(vector2d<real>(x, y)), rotation(0), scale(vector2d<real>()) {}

		Transform(const real x, const real y, const real rotation) : position(vector2d<real>(x, y)), rotation(rotation), scale(vector2d<real>()) {}

		Transform(const real x, const real y, const real rotation, const vector2d<real> scale) : position(vector2d<real>(x, y)), rotation(rotation), scale(scale) {}

		Transform(const real x, const real y, const real rotation, const real scaleX, const real scaleY) : position(vector2d<real>(x, y)), rotation(rotation), scale(vector2d<real>(scaleX, scaleY)) {}


	private:

	};
}