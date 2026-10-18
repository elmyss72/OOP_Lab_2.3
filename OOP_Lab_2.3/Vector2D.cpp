#include "Vector2D.h"
#include <cmath>
#include <sstream>

// Перевірка значень, щоб унеможливити обхід валідації
void Vector2D::setX(double value) {
    if (value >= -100000.0 && value <= 100000.0) {
        x = value;
    }
    else {
        std::cerr << "Помилка: координата x виходить за допустимі межі! Встановлено 0." << std::endl;
        x = 0.0;
    }
}

void Vector2D::setY(double value) {
    if (value >= -100000.0 && value <= 100000.0) {
        y = value;
    }
    else {
        std::cerr << "Помилка: координата y виходить за допустимі межі! Встановлено 0." << std::endl;
        y = 0.0;
    }
}

double Vector2D::getX() const { return x; }
double Vector2D::getY() const { return y; }

// Конструктори
Vector2D::Vector2D() : x(0.0), y(0.0) {}

Vector2D::Vector2D(double xVal, double yVal) {
    setX(xVal);
    setY(yVal);
}

Vector2D::Vector2D(const Vector2D& other) : x(other.x), y(other.y) {}

Vector2D::~Vector2D() {}

// Логіка вектора
double Vector2D::length() const {
    return std::sqrt(x * x + y * y);
}

// Присвоєння
Vector2D& Vector2D::operator=(const Vector2D& other) {
    if (this != &other) {
        x = other.x;
        y = other.y;
    }
    return *this;
}

// Приведення до рядка
Vector2D::operator std::string() const {
    std::stringstream ss;
    ss << "(" << x << "; " << y << ")";
    return ss.str();
}

// Інкременти та декременти
Vector2D& Vector2D::operator++() {
    setX(x + 1.0);
    return *this;
}

Vector2D& Vector2D::operator--() {
    setX(x - 1.0);
    return *this;
}

Vector2D Vector2D::operator++(int) {
    Vector2D temp(*this);
    setY(y + 1.0);
    return temp;
}

Vector2D Vector2D::operator--(int) {
    Vector2D temp(*this);
    setY(y - 1.0);
    return temp;
}

// Скалярний добуток
double operator*(const Vector2D& a, const Vector2D& b) {
    return (a.x * b.x) + (a.y * b.y);
}

// Множення на скаляр
Vector2D operator*(const Vector2D& v, double scalar) {
    return Vector2D(v.x * scalar, v.y * scalar);
}

Vector2D operator*(double scalar, const Vector2D& v) {
    return Vector2D(v.x * scalar, v.y * scalar);
}

// Порівняння довжин векторів
bool operator==(const Vector2D& a, const Vector2D& b) {
    return std::abs(a.length() - b.length()) < 1e-9; // Порівняння double з точністю
}

bool operator!=(const Vector2D& a, const Vector2D& b) {
    return !(a == b);
}

bool operator>(const Vector2D& a, const Vector2D& b) {
    return a.length() > b.length() + 1e-9;
}

bool operator<(const Vector2D& a, const Vector2D& b) {
    return a.length() < b.length() - 1e-9;
}

// Введення/виведення
std::ostream& operator<<(std::ostream& out, const Vector2D& v) {
    out << std::string(v);
    return out;
}

std::istream& operator>>(std::istream& in, Vector2D& v) {
    double tempX, tempY;
    std::cout << " x: ";
    in >> tempX;
    std::cout << " y: ";
    in >> tempY;

    v.setX(tempX);
    v.setY(tempY);
    return in;
}