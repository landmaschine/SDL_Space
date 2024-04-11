#pragma once
#include <iostream>
#include <cmath>

template<typename T>
struct Vector2 {
    T x, y;

    Vector2() : x(0), y(0) {}
    Vector2(T p_x, T p_y) : x(p_x), y(p_y) {}

    Vector2<T> normalize() const {
        T length = std::hypot(x, y);
        if (length != 0) {
            return {x / length, y / length};
        }
        return {0, 0};
    }

    Vector2<T> operator+(const Vector2<T>& vec) const {
        return {x + vec.x, y + vec.y};
    }

    Vector2<T> operator-(const Vector2<T>& vec) const {
        return {x - vec.x, y - vec.y};
    }

    Vector2<T> operator*(const Vector2<T>& vec) const {
        return {x * vec.x, y * vec.y};
    }

    Vector2<T> operator*(T scalar) const {
        return {x * scalar, y * scalar};
    }

    Vector2<T> operator/(const Vector2<T>& vec) const {
        return {x / vec.x, y / vec.y};
    }

    Vector2<T> operator+=(const Vector2<T>& vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2<T> operator-=(const Vector2<T>& vec) {
        x -= vec.x;
        y -= vec.y;
        return *this;
    }

    Vector2<T> operator*=(const Vector2<T>& vec) {
        x *= vec.x;
        y *= vec.y;
        return *this;
    }

    Vector2<T> operator*=(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2<T> operator/=(const Vector2<T>& vec) {
        x /= vec.x;
        y /= vec.y;
        return *this;
    }

    void print() const {
        std::cout << x << ", " << y << std::endl;
    }
};
