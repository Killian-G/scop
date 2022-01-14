//
// Created by killian on 01/01/2022.
//

#ifndef VECTOR3_HPP
#define VECTOR3_HPP

#include <iostream>
#include <sstream>

template <typename T>
class Vector3 {
public:
	T x;
	T y;
	T z;

	Vector3() = default;
	Vector3(T X, T Y, T Z);
	explicit Vector3(T scale);
	Vector3(const Vector3<T>& vec) = default;
	~Vector3() = default;

	Vector3<T>& Set(T X, T Y, T Z);
	Vector3<T>& Set(T scale);

	Vector3<T> CrossProduct(const Vector3<T>& vec) const;
	T DotProduct(const Vector3<T>& vec) const;


	[[nodiscard]] std::string ToString() const;
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Vector3<U>& vec);
	Vector3<T> operator-() const;
	Vector3<T> operator+(const Vector3<T>& vec) const;
	Vector3<T> operator-(const Vector3<T>& vec) const;
	Vector3<T> operator*(T scale) const;
	Vector3<T> operator*(const Vector3<T>& vec) const;
	Vector3<T> operator/(T scale) const;
	Vector3<T> operator/(const Vector3<T>& vec) const;
	Vector3<T>& operator+=(const Vector3<T>& vec) const;
	Vector3<T>& operator-=(const Vector3<T>& vec) const;
	Vector3<T>& operator*=(const Vector3<T>& vec) const;
	Vector3<T>& operator/=(const Vector3<T>& vec) const;
};

using Vector3f = Vector3<float>;
using Vector3d = Vector3<double>;
using Vector3i = Vector3<int32_t>;
using Vector3ui = Vector3<u_int32_t>;

#include "Vector3.inl"

#endif //VECTOR3_HPP
