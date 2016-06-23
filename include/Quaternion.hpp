#ifndef MYUPLAY_MYENGINE_QUATERNION
#define MYUPLAY_MYENGINE_QUATERNION

#include <functional>
#include <vector>

#include "Euler.hpp"
#include "Vector3.hpp"
#include "Matrix4.hpp"
#include "Math.hpp"

namespace MyUPlay {

	namespace MyEngine {

		//Euler must be completely loaded, it cannot be forward declared due to Order enum.
		/*
		#ifndef EULER_DEFINED
		template <typename T> class Euler;
		#endif
		*/

		#ifndef VECTOR3_DEFINED
		template <typename T> class Vector3;
		#endif

		#ifndef MATRIX4_DEFINED
		template <typename T> class Matrix4;
		#endif

		template <typename T>
		class Quaternion {

		public:

			T x, y, z, w;

			std::function<void()> onChangeCallback = [](){return 0;}; //Does nothing but can be overwritten.

			Quaternion(T x = 0, T y = 0, T z = 0, T w = 1)
				:x(x), y(y), z(z), w(w){
				onChangeCallback(); //The constructor can be called after creation as a set.
			}

			Quaternion(const Quaternion& q) : x(q.x), y(q.y), z(q.z), w(q.w){
				onChangeCallback(); //The constructor can be called after creation as a copy.
			}

			T getX() const {
				return x;
			}

			T getY() const {
				return y;
			}

			T getZ() const {
				return z;
			}

			T getW() const {
				return w;
			}

			void setX(T n) {
				x = n;
				onChangeCallback();
			}

			void setY(T n) {
				y = n;
				onChangeCallback();
			}

			void setZ(T n) {
				z = n;
				onChangeCallback();
			}

			void setW(T n) {
				w = n;
				onChangeCallback();
			}

			Quaternion& onChange(std::function<void()> callback){
				onChangeCallback = callback;
				return *this;
			}

			Quaternion& copy(const Quaternion& q){
				x = q.x;
				y = q.y;
				z = q.z;
				w = q.w;

				onChangeCallback();

				return *this;
			}

			Quaternion& operator=(const Quaternion& q){
				return copy(q);
			}

			Quaternion clone() const {
				return Quaternion(*this);
			}

			Quaternion& setFromEuler(const Euler<T>& euler, bool update = true){
				T c1 = cos(euler.x / 2);
				T c2 = cos(euler.y / 2);
				T c3 = cos(euler.z / 2);
				T s1 = sin(euler.x / 2);
				T s2 = sin(euler.y / 2);
				T s3 = sin(euler.z / 2);

				const Order& order = euler.order;

				if ( order == Order::XYZ ) {

					x = s1 * c2 * c3 + c1 * s2 * s3;
					y = c1 * s2 * c3 - s1 * c2 * s3;
					z = c1 * c2 * s3 + s1 * s2 * c3;
					w = c1 * c2 * c3 - s1 * s2 * s3;

				} else if ( order == Order::YXZ ) {

					x = s1 * c2 * c3 + c1 * s2 * s3;
					y = c1 * s2 * c3 - s1 * c2 * s3;
					z = c1 * c2 * s3 - s1 * s2 * c3;
					w = c1 * c2 * c3 + s1 * s2 * s3;

				} else if ( order == Order::ZXY ) {

					x = s1 * c2 * c3 - c1 * s2 * s3;
					y = c1 * s2 * c3 + s1 * c2 * s3;
					z = c1 * c2 * s3 + s1 * s2 * c3;
					w = c1 * c2 * c3 - s1 * s2 * s3;

				} else if ( order == Order::ZYX ) {

					x = s1 * c2 * c3 - c1 * s2 * s3;
					y = c1 * s2 * c3 + s1 * c2 * s3;
					z = c1 * c2 * s3 - s1 * s2 * c3;
					w = c1 * c2 * c3 + s1 * s2 * s3;

				} else if ( order == Order::YZX ) {

					x = s1 * c2 * c3 + c1 * s2 * s3;
					y = c1 * s2 * c3 + s1 * c2 * s3;
					z = c1 * c2 * s3 - s1 * s2 * c3;
					w = c1 * c2 * c3 - s1 * s2 * s3;

				} else if ( order == Order::XZY ) {

					x = s1 * c2 * c3 - c1 * s2 * s3;
					y = c1 * s2 * c3 - s1 * c2 * s3;
					z = c1 * c2 * s3 + s1 * s2 * c3;
					w = c1 * c2 * c3 + s1 * s2 * s3;

				}

				if (update) onChangeCallback();

				return *this;

			}

			Quaternion& setFromAxisAngle(const Vector3<T>& axis, T angle){
				T halfAngle = angle / 2;
				T s = sin(halfAngle);

				x = axis.x * s;
				y = axis.y * s;
				z = axis.z * s;
				w = cos(halfAngle);

				onChangeCallback();

				return *this;

			}

			Quaternion& setFromRotationMatrix(const Matrix4<T>& m) {
				const auto& te = m.elements;
				const T& m11 = te[ 0 ], m12 = te[ 4 ], m13 = te[ 8 ],
					 m21 = te[ 1 ], m22 = te[ 5 ], m23 = te[ 9 ],
					 m31 = te[ 2 ], m32 = te[ 6 ], m33 = te[ 10 ];

				T trace = m11 + m22 + m33;
				T s;

				if ( trace > 0 ) {

					s = 0.5 / sqrt( trace + 1.0 );

					w = 0.25 / s;
					x = ( m32 - m23 ) * s;
					y = ( m13 - m31 ) * s;
					z = ( m21 - m12 ) * s;

				} else if ( m11 > m22 && m11 > m33 ) {

					s = 2.0 * sqrt( 1.0 + m11 - m22 - m33 );

					w = ( m32 - m23 ) / s;
					x = 0.25 * s;
					y = ( m12 + m21 ) / s;
					z = ( m13 + m31 ) / s;

				} else if ( m22 > m33 ) {

					s = 2.0 * sqrt( 1.0 + m22 - m11 - m33 );

					w = ( m13 - m31 ) / s;
					x = ( m12 + m21 ) / s;
					y = 0.25 * s;
					z = ( m23 + m32 ) / s;

				} else {

					s = 2.0 * sqrt( 1.0 + m33 - m11 - m22 );

					w = ( m21 - m12 ) / s;
					x = ( m13 + m31 ) / s;
					y = ( m23 + m32 ) / s;
					z = 0.25 * s;

				}

				onChangeCallback();

				return *this;

			}

			Quaternion& setFromUnitVectors(const Vector3<T>& from, const Vector3<T>& to){

				Vector3<T> v1;
				const T EPS = 0.000001;

				T r = from.dot( to ) + 1;

				if ( r < EPS ) {

					r = 0;

					if ( abs( from.x ) > abs( from.z ) ) {

						v1.set( - from.y, from.x, 0 );

					} else {

						v1.set( 0, - from.z, from.y );

					}

				} else {

					v1.crossVectors( from, to );

				}

				x = v1.x;
				y = v1.y;
				z = v1.z;
				w = r;

				return normalize();

			}

			Quaternion& inverse() {
				conjugate().normalize();

				return *this;
			}

			Quaternion& conjugate(){
				x *= -1;
				y *= -1;
				z *= -1;

				onChangeCallback();

				return *this;

			}

			T dot(Quaternion& q) const {
				return x * q.x + q * q.y + z * q.z + w * q.w;
			}

			T lengthSq() const {
				return x * x + y * y + z * z + w * w;
			}

			T length() const; //Avoiding including math.h in header.

			Quaternion& normalize();

			Quaternion& multiply(const Quaternion& q) {
				return multiplyQuaternions(*this, q);
			}

			Quaternion& multiplyQuaternions(const Quaternion&, const Quaternion&);

			Quaternion& operator*=(const Quaternion& q){
				return multiply(q);
			}

			Quaternion operator*(const Quaternion& q) const {
				return Quaternion(*this).multiply(q);
			}

			Quaternion& slerp(const Quaternion&, T interpolation);

			bool equals(const Quaternion& q) const {
				return x == q.x && y == q.y && z == q.z && w == q.w;
			}

			bool operator==(const Quaternion& q) const {
				return equals(q);
			}

			Quaternion& fromArray(std::vector<Quaternion>& array, unsigned offset = 0) {

				x = array[offset];
				y = array[offset + 1];
				z = array[offset + 2];
				w = array[offset + 3];

				onChangeCallback();

				return *this;

			}

			std::vector<Quaternion> toArray(std::vector<Quaternion>& array, unsigned offset = 0) const {

				array.reserve(offset + 3);
				array[offset] = x;
				array[offset + 1] = y;
				array[offset + 2] = z;
				array[offset + 3] = w;

				return array;

			}

			static inline Quaternion& slerp(const Quaternion& a, const Quaternion& b, Quaternion& target, T interpolation){
				return target(a).slerp(b, interpolation);
			}

		};

		typedef Quaternion<float> Quaternionf;
		typedef Quaternion<double> Quaterniond;

		#define QUATERNION_DEFINED

	}

}

#endif
