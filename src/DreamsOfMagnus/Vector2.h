#pragma once
#include "precision.h"

namespace DreamsOfMagnus {
	/*
	* A vector with an x, y, and z component
	*
	*/
	template <class T>
	class Vector2 {
	public:
		//The x component of this vector
		T x;

		//The y component of this vector
		T y;

	public:
		/*
		*The default Vector2 constructor sets all components to 0
		*/
		Vector2() : x(0), y(0) {}

		Vector2(const T x, const T y) : x(x), y(y) {}

		/*
		* Returns the squared magnitude of this Vector2
		* Square magnitude is faster to calculate than the actual magnitude
		*/
		T squareMagnitude() const {
			return x * x + y * y;
		}

		/*
		* Flips the sign of every component in this Vector2
		*/
		void invert() {
			x = -x;
			y = -y;
		}

		/** TODO:
		* Implement magnitude and normalize (depends on a sqrt function yet to be made)
		*/

		/*
		* Overrides the *= operator for multiplying a scalor to this Vector2
		*/
		void operator *=(const T other) {
			x *= other;
			y *= other;
		}

		/*
		* Overrides the * operator for multiplying a scalor to this Vector2
		*/
		Vector2 operator *(const Vector2 other) const {
			return Vector2(x * other.x, y * other.y);
		}

		/*
		* Overrides the += operator for adding a Vector2 to this Vector2
		*/
		void operator +=(const Vector2 other) {
			x += other.x;
			y += other.y;
		}

		/*
		* Overrides the + operator for adding a Vector2 to this Vector2
		*/
		Vector2 operator +(const Vector2 other) const {
			return Vector2(x + other.x, y + other.y);
		}

		/*
		* Overrides the -= operator for subtracting a Vector2 from this Vector2
		*/
		void operator -=(const Vector2 other) {
			x -= other.x;
			y -= other.y;
		}

		/*
		* Overrides the - operator for subtracting a Vector2 from this Vector2
		*/
		Vector2 operator -(const Vector2 other) const {
			return Vector2(x - other.x, y - other.y);
		}

		/*
		* Calculates the dot product of this Vector2 and the one passed as a parameter
		*/
		T dotProduct(const Vector2 other) const {
			return (x * other.x) + (y * other.y);
		}
	};
}