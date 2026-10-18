
#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP_Lab_2.3/Vector2D.cpp"

#include <string>
#include <sstream>
#include <cmath>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Vector2DUnitTests
{
    TEST_CLASS(Vector2DTests)
    {
    public:

        // 1. Конструктор за замовчуванням
        TEST_METHOD(DefaultConstructor)
        {
            Vector2D v;

            Assert::AreEqual(0.0, v.getX(), 1e-9);
            Assert::AreEqual(0.0, v.getY(), 1e-9);
            Assert::AreEqual(0.0, v.length(), 1e-9);
        }

        // 2. Конструктор з координатами
        TEST_METHOD(ConstructorWithCoordinates)
        {
            Vector2D v(3.0, 4.0);

            Assert::AreEqual(3.0, v.getX(), 1e-9);
            Assert::AreEqual(4.0, v.getY(), 1e-9);
            Assert::AreEqual(5.0, v.length(), 1e-9);
        }

        // 3. Конструктор копіювання
        TEST_METHOD(CopyConstructor)
        {
            Vector2D v1(3.0, 4.0);
            Vector2D v2(v1);

            Assert::AreEqual(v1.getX(), v2.getX(), 1e-9);
            Assert::AreEqual(v1.getY(), v2.getY(), 1e-9);
        }

        // 4. Отримання координат
        TEST_METHOD(GetCoordinates)
        {
            Vector2D v(12.5, -7.5);

            Assert::AreEqual(12.5, v.getX(), 1e-9);
            Assert::AreEqual(-7.5, v.getY(), 1e-9);
        }

        // 5. Зміна координат
        TEST_METHOD(SetCoordinates)
        {
            Vector2D v;

            v.setX(10.0);
            v.setY(-20.0);

            Assert::AreEqual(10.0, v.getX(), 1e-9);
            Assert::AreEqual(-20.0, v.getY(), 1e-9);
        }

        // 6. Перевірка верхньої межі координат
        TEST_METHOD(SetCoordinates_UpperBoundary)
        {
            Vector2D v;

            v.setX(100000.0);
            v.setY(100000.0);

            Assert::AreEqual(100000.0, v.getX(), 1e-9);
            Assert::AreEqual(100000.0, v.getY(), 1e-9);
        }

        // 7. Перевірка нижньої межі координат
        TEST_METHOD(SetCoordinates_LowerBoundary)
        {
            Vector2D v;

            v.setX(-100000.0);
            v.setY(-100000.0);

            Assert::AreEqual(-100000.0, v.getX(), 1e-9);
            Assert::AreEqual(-100000.0, v.getY(), 1e-9);
        }

        // 8. Перевірка виходу за межі координат
        TEST_METHOD(SetCoordinates_OutOfRange)
        {
            Vector2D v(10.0, 20.0);

            v.setX(100001.0);
            v.setY(-100001.0);

            Assert::AreEqual(0.0, v.getX(), 1e-9);
            Assert::AreEqual(0.0, v.getY(), 1e-9);
        }

        // 9. Обчислення довжини
        TEST_METHOD(LengthCalculation)
        {
            Vector2D v(3.0, 4.0);

            Assert::AreEqual(5.0, v.length(), 1e-9);
        }

        // 10. Довжина нульового вектора
        TEST_METHOD(ZeroVectorLength)
        {
            Vector2D v(0.0, 0.0);

            Assert::AreEqual(0.0, v.length(), 1e-9);
        }

        // 11. Оператор присвоєння
        TEST_METHOD(AssignmentOperator)
        {
            Vector2D v1(5.0, 6.0);
            Vector2D v2;

            v2 = v1;

            Assert::AreEqual(5.0, v2.getX(), 1e-9);
            Assert::AreEqual(6.0, v2.getY(), 1e-9);
        }

        // 12. Присвоєння самому собі
        TEST_METHOD(SelfAssignment)
        {
            Vector2D v(7.0, 8.0);

            v = v;

            Assert::AreEqual(7.0, v.getX(), 1e-9);
            Assert::AreEqual(8.0, v.getY(), 1e-9);
        }

        // 13. Перетворення в string
        TEST_METHOD(StringConversion)
        {
            Vector2D v(3.0, 4.0);

            std::string result = static_cast<std::string>(v);

            Assert::AreEqual(std::string("(3; 4)"), result);
        }

        // 14. Префіксний інкремент
        TEST_METHOD(PrefixIncrement)
        {
            Vector2D v(1.0, 2.0);

            Vector2D& result = ++v;

            Assert::AreEqual(2.0, v.getX(), 1e-9);
            Assert::AreEqual(2.0, v.getY(), 1e-9);
            Assert::IsTrue(&result == &v);
        }

        // 15. Префіксний декремент
        TEST_METHOD(PrefixDecrement)
        {
            Vector2D v(5.0, 6.0);

            --v;

            Assert::AreEqual(4.0, v.getX(), 1e-9);
            Assert::AreEqual(6.0, v.getY(), 1e-9);
        }

        // 16. Постфіксний інкремент
        TEST_METHOD(PostfixIncrement)
        {
            Vector2D v(1.0, 2.0);

            Vector2D old = v++;

            Assert::AreEqual(1.0, old.getX(), 1e-9);
            Assert::AreEqual(2.0, old.getY(), 1e-9);
            Assert::AreEqual(1.0, v.getX(), 1e-9);
            Assert::AreEqual(3.0, v.getY(), 1e-9);
        }

        // 17. Постфіксний декремент
        TEST_METHOD(PostfixDecrement)
        {
            Vector2D v(1.0, 5.0);

            Vector2D old = v--;

            Assert::AreEqual(1.0, old.getX(), 1e-9);
            Assert::AreEqual(5.0, old.getY(), 1e-9);
            Assert::AreEqual(1.0, v.getX(), 1e-9);
            Assert::AreEqual(4.0, v.getY(), 1e-9);
        }

        // 18. Скалярний добуток
        TEST_METHOD(DotProduct)
        {
            Vector2D a(1.0, 2.0);
            Vector2D b(3.0, 4.0);

            double result = a * b;

            Assert::AreEqual(11.0, result, 1e-9);
        }

        // 19. Множення вектора на скаляр
        TEST_METHOD(VectorTimesScalar)
        {
            Vector2D v(3.0, 4.0);

            Vector2D result = v * 2.0;

            Assert::AreEqual(6.0, result.getX(), 1e-9);
            Assert::AreEqual(8.0, result.getY(), 1e-9);

            // Початковий вектор не змінюється
            Assert::AreEqual(3.0, v.getX(), 1e-9);
            Assert::AreEqual(4.0, v.getY(), 1e-9);
        }

        // 20. Множення скаляра на вектор
        TEST_METHOD(ScalarTimesVector)
        {
            Vector2D v(3.0, -4.0);

            Vector2D result = 3.0 * v;

            Assert::AreEqual(9.0, result.getX(), 1e-9);
            Assert::AreEqual(-12.0, result.getY(), 1e-9);
        }

        // 21. Порівняння рівних довжин
        TEST_METHOD(EqualOperator)
        {
            Vector2D a(3.0, 4.0);
            Vector2D b(0.0, 5.0);

            Assert::IsTrue(a == b);
        }

        // 22. Порівняння нерівних довжин
        TEST_METHOD(NotEqualOperator)
        {
            Vector2D a(3.0, 4.0);
            Vector2D b(6.0, 8.0);

            Assert::IsTrue(a != b);
        }

        // 23. Оператор >
        TEST_METHOD(GreaterThanOperator)
        {
            Vector2D a(6.0, 8.0);
            Vector2D b(3.0, 4.0);

            Assert::IsTrue(a > b);
        }

        // 24. Оператор <
        TEST_METHOD(LessThanOperator)
        {
            Vector2D a(3.0, 4.0);
            Vector2D b(6.0, 8.0);

            Assert::IsTrue(a < b);
        }

        // 25. Виведення через <<
        TEST_METHOD(OutputOperator)
        {
            Vector2D v(3.0, 4.0);

            std::ostringstream out;
            out << v;

            Assert::AreEqual(std::string("(3; 4)"), out.str());
        }
    };
}
