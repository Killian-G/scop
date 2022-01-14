//
// Created by killian on 01/01/2022.
//

#include "Vector2.hpp"

/*!
 * @remark This Vector2 class is in "Right-Hand" coordinate space
 */

/*!
 * @brief Constructs a new Vector2 object from three components
 * @param X X component
 * @param Y Y component
 * @param Z Z component
 */
template<typename T>
Vector2<T>::Vector2(T X, T Y)
{
	Set(X, Y);
}

/*!
 * @brief Constructs a new Vector2 with three components with same value
 * @param scale
 */
template<typename T>
Vector2<T>::Vector2(T scale)
{
	Set(scale);
}

/*!
 * @brief
 * @return
 */
template<typename T>
std::string Vector2<T>::ToString() const
{
	std::stringstream ss;

	return "Vector2(" + std::to_string(this->x) + ", " + std::to_string(this->y) + ", " + std::to_string(this->z) + ')';
}

template<typename U>
std::ostream &operator<<(std::ostream &os, const Vector2<U> &vec)
{
	os << vec.ToString();
	return os;
}

template<typename T>
Vector2<T>& Vector2<T>::Set(T X, T Y)
{
	x = X;
	y = Y;
	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::Set(T scale)
{
	x = scale;
	y = scale;

	return *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator-() const
{
	return Vector2<T>(-x, -y);
}

template<typename T>
Vector2<T> Vector2<T>::operator+(const Vector2<T>& vec) const
{
	return Vector2<T>(x + vec.x, y + vec.y);
}

template<typename T>
Vector2<T> Vector2<T>::operator*(T scale) const
{
	return Vector2<T>(x * scale, y * scale);
}

template<typename T>
Vector2<T> Vector2<T>::operator/(T scale) const
{
	return Vector2<T>(x / scale, y / scale);
}

template<typename T>
Vector2<T> Vector2<T>::operator-(const Vector2<T>& vec) const
{
	return Vector2<T>(x - vec.x, y - vec.y);
}

template<typename T>
Vector2<T>& Vector2<T>::operator+=(const Vector2<T>& vec) const
{
	x += vec.x;
	y += vec.y;
	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator-=(const Vector2<T>& vec) const
{
	x -= vec.x;
	y -= vec.y;
	return *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator*=(const Vector2<T>& vec) const
{
	x *= vec.x;
	y *= vec.y;
	this *this;
}

template<typename T>
Vector2<T>& Vector2<T>::operator/=(const Vector2<T>& vec) const
{
	x /= vec.x;
	y /= vec.y;
	this *this;
}

template<typename T>
Vector2<T> Vector2<T>::operator*(const Vector2<T>& vec) const
{
	return Vector2<T>(x * vec.x, y * vec.y);
}

template<typename T>
float Vector2<T>::CrossProduct(const Vector2<T>& vec) const
{
	return x * vec.y - y * vec.x;
}

template<typename T>
T Vector2<T>::DotProduct(const Vector2<T>& vec) const
{
	return x * vec.x + y * vec.y;
}

template<typename T>
Vector2<T> Vector2<T>::operator/(const Vector2<T>& vec) const
{
	return Vector2<T>(x / vec.x, y / vec.y);
}

