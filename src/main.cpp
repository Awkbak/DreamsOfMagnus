#include <irrlicht.h>
#include "DreamsOfMagnus/Vector3.h"
#include "DreamsOfMagnus/Object.h"
#include "DreamsOfMagnus/Collisions.h"
#include <stdio.h>
#include <sys\timeb.h>

using namespace irr;
using namespace core;
using namespace scene;
using namespace video;
using namespace io;
using namespace gui;
using namespace DreamsOfMagnus;
using namespace DreamObjects;

#pragma comment(lib, "Irrlicht.lib")

int main(int argc, char* argv[]) {
	RectangleCollider c1 = RectangleCollider(Transform(0, 0), 1);
	CircleCollider c2 = CircleCollider(Transform(1.5f, 1.5f), 1.0f);
	vector2d<real> collisionDirection = c1.collisionDirectionNormalized(c2);
	printf("%d %f %f\n", c1.isColliding(c2), collisionDirection.X, collisionDirection.Y);
	return 0;

}
