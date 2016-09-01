#pragma once
#include "precision.h"

namespace DreamsOfMagnus {
	/*
	* A vector with an x, y, and z component
	*
	*/
	template <class T>
	class Vector3 {
	public:
		//The x component of this vector
		T x;

		//The y component of this vector
		T y;

		//The z component of this vector
		T z;

	private:
		//Adds padding to make this class have a four word (64-bit alignment)
		T padding;

	public:
		/*
		*The default Vector3 constructor sets all components to 0
		*/
		Vector3() : x(0), y(0), z(0) {}

		Vector3(const T x, const T y, const T z) : x(x), y(y), z(z) {}

		/*
		* Returns the squared magnitude of this Vector3
		* Square magnitude is faster to calculate than the actual magnitude
		*/
		T squareMagnitude() const {
			return x * x + y * y + z * z;
		}

		/*
		* Flips the sign of every component in this Vector3
		*/
		void invert() {
			x = -x;
			y = -y;
			z = -z;
		}

		/** TODO:
		* Implement magnitude and normalize (depends on a sqrt function yet to be made)
		*/

		/*
		* Overrides the *= operator for multiplying a scalor to this Vector3
		*/
		void operator *=(const T other) {
			x *= other;
			y *= other;
			z *= other;
		}

		/*
		* Overrides the * operator for multiplying a scalor to this Vector3
		*/
		Vector3 operator *(const T other) const {
			return Vector3<T>(x * other, y * other, z * other);
		}

		/*
		* Overrides the *= operator for multiplying a Vector3 to this Vector3
		*/
		void operator *=(const Vector3 other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
		}

		/*
		* Overrides the * operator for multiplying a Vector3 to this Vector3
		*/
		Vector3 operator *(const Vector3 other) const {
			return Vector3<T>(x * other.x, y * other.y, z * other.z);
		}


		/*
		* Overrides the/*= operator for dividing a Vector3 from this Vector3
		*/
		void operator /=(const Vector3 other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
		}

		/*
		* Overrides the / operator for dividing a scalor from this Vector3
		*/
		Vector3 operator /(const Vector3 other) const {
			return Vector3<T>(x / other.x, y / other.y, z / other.z);
		}

		/*
		* Overrides the += operator for adding a Vector3 to this Vector3
		*/
		void operator +=(const Vector3 other) {
			x += other.x;
			y += other.y;
			z += other.z;
		}

		/*
		* Overrides the + operator for adding a Vector3 to this Vector3
		*/
		Vector3 operator +(const Vector3 other) const {
			return Vector3<T>(x + other.x, y + other.y, z + other.z);
		}

		/*
		* Overrides the -= operator for subtracting a Vector3 from this Vector3
		*/
		void operator -=(const Vector3 other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
		}

		/*
		* Overrides the - operator for subtracting a Vector3 from this Vector3
		*/
		Vector3 operator -(const Vector3 other) const {
			return Vector3<T>(x - other.x, y - other.y, z - other.z);
		}

		/*
		* Calculates the cross product of this Vector3 and the one passed as a parameter
		*/
		Vector3 crossProduct(const Vector3 other) const {
			return Vector3<T>((y * other.z) - (z * other.y), (x * other.z) - (z * other.x), (x * other.y) - (y * other.x));
		}

		/*
		* Calculates the dot product of this Vector3 and the one passed as a parameter
		*/
		T dotProduct(const Vector3 other) const {
			return (x * other.x) + (y * other.y) + (z * other.z);
		}
	};
}
