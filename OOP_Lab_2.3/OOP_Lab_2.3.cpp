#include <iostream>
#include "Vector2D.h"

// Демонстрація вирівнювання пам'яті (pack)
#pragma pack(push, 1)
class Vector2DPacked {
    double x, y;
};
#pragma pack(pop)

int main() {
    setlocale(LC_ALL, "uk_UA.UTF-8");

    std::cout << "--- РОЗМІР КЛАСУ ---\n";
    std::cout << "Без #pragma pack: " << sizeof(Vector2D) << " байт\n";
    std::cout << "З #pragma pack(1): " << sizeof(Vector2DPacked) << " байт\n\n";

    std::cout << "--- СТВОРЕННЯ ВЕКТОРІВ ТА ВВЕДЕННЯ ---\n";
    Vector2D v1; // Конструктор за умовчанням
    std::cout << "Введіть координати для вектора v1:\n";
    std::cin >> v1;

    Vector2D v2(3.0, 4.0); // Конструктор ініціалізації
    std::cout << "\nВектор v2 ініціалізовано: " << v2 << " (Довжина: " << v2.length() << ")\n";

    Vector2D v3 = v1; // Конструктор копіювання
    std::cout << "Вектор v3 (копія v1): " << v3 << "\n\n";

    std::cout << "--- МАТЕМАТИЧНІ ОПЕРАЦІЇ ---\n";
    double scalarProd = v1 * v2;
    std::cout << "Скалярний добуток v1 * v2 = " << scalarProd << "\n";

    double scalar;
    std::cout << "Введіть скаляр для множення v2: ";
    std::cin >> scalar;
    Vector2D v4 = v2 * scalar;
    std::cout << "v2 * " << scalar << " = " << v4 << "\n\n";

    std::cout << "--- ПОРІВНЯННЯ ДОВЖИН ---\n";
    std::cout << "Довжина v1: " << v1.length() << "\n";
    std::cout << "Довжина v2: " << v2.length() << "\n";
    if (v1 > v2) std::cout << "v1 довший за v2\n";
    else if (v1 < v2) std::cout << "v1 коротший за v2\n";
    else std::cout << "Вектори мають однакову довжину (==)\n";

    std::cout << "\n--- ІНКРЕМЕНТИ ТА ДЕКРЕМЕНТИ ---\n";
    std::cout << "Початковий v1: " << v1 << "\n";
    ++v1;
    std::cout << "Після ++v1 (змінюється x): " << v1 << "\n";
    v1++;
    std::cout << "Після v1++ (змінюється y): " << v1 << "\n";

    std::cout << "\n--- МАСИВ ОБ'ЄКТІВ ---\n";
    Vector2D arr[3] = { Vector2D(1, 1), Vector2D(2, -2), Vector2D(0, 5) };
    for (int i = 0; i < 3; i++) {
        std::cout << "arr[" << i << "] = " << arr[i] << " довжина: " << arr[i].length() << "\n";
    }

    return 0;
}