//
// Created by killian on 01/01/2022.
//

#include "Vector3.hpp"

/*!
 * @remark This Vector3 class is in "Right-Hand" coordinate space
 */

/*!
 * @brief Constructs a new Vector3 object from three components
 * @param X X component
 * @param Y Y component
 * @param Z Z component
 */
template<typename T>
Vector3<T>::Vector3(T X, T Y, T Z)
{
	Set(X, Y, Z);
}

/*!
 * @brief Constructs a new Vector3 with three components with same value
 * @param scale
 */
template<typename T>
Vector3<T>::Vector3(T scale)
{
	Set(scale);
}

/*!
 * @brief
 * @return
 */
template<typename T>
std::string Vector3<T>::ToString() const
{
	std::stringstream ss;

	return "Vector3(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ')';
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Vector3<U> &vec)
{
	os << vec.ToString();
	return os;
}

template<typename T>
Vector3<T>& Vector3<T>::Set(T X, T Y, T Z)
{
	x = X;
	y = Y;
	z = Z;
	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::Set(T scale)
{
	x = scale;
	y = scale;
	z = scale;

	return *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator-() const
{
	return Vector3<T>(-x, -y, -z);
}

template<typename T>
Vector3<T> Vector3<T>::operator+(const Vector3<T>& vec) const
{
	return Vector3<T>(x + vec.x, y + vec.y, z + vec.z);
}

template<typename T>
Vector3<T> Vector3<T>::operator*(T scale) const
{
	return Vector3<T>(x * scale, y * scale, z * scale);
}

template<typename T>
Vector3<T> Vector3<T>::operator/(T scale) const
{
	return Vector3<T>(x / scale, y / scale, z / scale);
}

template<typename T>
Vector3<T> Vector3<T>::operator-(const Vector3<T>& vec) const
{
	return Vector3<T>(x - vec.x, y - vec.y, z - vec.z);
}

template<typename T>
Vector3<T>& Vector3<T>::operator+=(const Vector3<T>& vec) const
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator-=(const Vector3<T>& vec) const
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator*=(const Vector3<T>& vec) const
{
	x *= vec.x;
	y *= vec.y;
	z *= vec.z;
	this *this;
}

template<typename T>
Vector3<T>& Vector3<T>::operator/=(const Vector3<T>& vec) const
{
	x /= vec.x;
	y /= vec.y;
	z /= vec.z;
	this *this;
}

template<typename T>
Vector3<T> Vector3<T>::operator*(const Vector3<T>& vec) const
{
	return Vector3<T>(x * vec.x, y * vec.y, z * vec.z);
}

template<typename T>
Vector3<T> Vector3<T>::CrossProduct(const Vector3<T>& vec) const
{
	return Vector3<T>(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
}

template<typename T>
T Vector3<T>::DotProduct(const Vector3<T>& vec) const
{
	return x * vec.x + y * vec.y + z * vec.z;
}

template<typename T>
Vector3<T> Vector3<T>::operator/(const Vector3<T>& vec) const
{
	return Vector3<T>(x / vec.x, y / vec.y, z / vec.z);
}

