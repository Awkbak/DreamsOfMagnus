

#include vector2d
#include vector3d

namespace gravityforce {
private :
	real gravityAcc = -9.8;
public :
	void applyGravity(vector2d velocity) {
		velocity.y += (gravityAcc * timeStep);
	}
	void applyGravity(vector3d velocity) {
		velocity.y += (gravityAcc * timestep);
	}
	void changeGravity(real g) {
		gravityAcc = g;
	}
}