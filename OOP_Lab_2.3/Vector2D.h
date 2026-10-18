#pragma once
#include <iostream>
#include <string>

class Vector2D {
private:
    double x;
    double y;

public:
    // Методи доступу
    double getX() const;
    double getY() const;
    void setX(double value);
    void setY(double value);

    // Конструктори та деструктор
    Vector2D();
    Vector2D(double xVal, double yVal);
    Vector2D(const Vector2D& other);
    ~Vector2D();

    // Обчислення довжини вектора
    double length() const;

    // Перевантаження операції присвоєння (метод класу)
    Vector2D& operator=(const Vector2D& other);

    // Приведення типу до string (метод класу)
    operator std::string() const;

    // Перевантаження унарних операцій інкременту/декременту (методи класу)
    // Префіксні модифікують x, постфіксні модифікують y
    Vector2D& operator++();    // ++v
    Vector2D& operator--();    // --v
    Vector2D operator++(int);  // v++
    Vector2D operator--(int);  // v--

    // Бінарні операції (зовнішні дружні функції)

    // Скалярний добуток
    friend double operator*(const Vector2D& a, const Vector2D& b);

    // Множення на скаляр
    friend Vector2D operator*(const Vector2D& v, double scalar);
    friend Vector2D operator*(double scalar, const Vector2D& v);

    // Порівняння довжин векторів
    friend bool operator==(const Vector2D& a, const Vector2D& b);
    friend bool operator!=(const Vector2D& a, const Vector2D& b);
    friend bool operator>(const Vector2D& a, const Vector2D& b);
    friend bool operator<(const Vector2D& a, const Vector2D& b);

    // Введення/виведення
    friend std::ostream& operator<<(std::ostream& out, const Vector2D& v);
    friend std::istream& operator>>(std::istream& in, Vector2D& v);
};