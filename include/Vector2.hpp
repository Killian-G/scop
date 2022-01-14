//
// Created by killian on 01/01/2022.
//

#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <iostream>
#include <sstream>

template <typename T>
class Vector2 {
public:
	T x;
	T y;

	Vector2() = default;
	Vector2(T X, T Y);
	explicit Vector2(T scale);
	Vector2(const Vector2<T>& vec) = default;
	~Vector2() = default;

	Vector2<T>& Set(T X, T Y);
	Vector2<T>& Set(T scale);

	float CrossProduct(const Vector2<T>& vec) const;
	T DotProduct(const Vector2<T>& vec) const;


	[[nodiscard]] std::string ToString() const;
	template<typename U>
	friend std::ostream& operator<<(std::ostream& os, const Vector2<U>& vec);
	Vector2<T> operator-() const;
	Vector2<T> operator+(const Vector2<T>& vec) const;
	Vector2<T> operator-(const Vector2<T>& vec) const;
	Vector2<T> operator*(T scale) const;
	Vector2<T> operator*(const Vector2<T>& vec) const;
	Vector2<T> operator/(T scale) const;
	Vector2<T> operator/(const Vector2<T>& vec) const;
	Vector2<T>& operator+=(const Vector2<T>& vec) const;
	Vector2<T>& operator-=(const Vector2<T>& vec) const;
	Vector2<T>& operator*=(const Vector2<T>& vec) const;
	Vector2<T>& operator/=(const Vector2<T>& vec) const;
};

using Vector2f = Vector2<float>;
using Vector2d = Vector2<double>;
using Vector2i = Vector2<int32_t>;
using Vector2ui = Vector2<u_int32_t>;

#include "Vector2.inl"

#endif //VECTOR2_HPP
