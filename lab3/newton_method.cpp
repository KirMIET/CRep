#include <iostream>
#include <cmath>
#include <stdexcept>
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

using namespace std;

double f(double x) {
    return x*x - 2;
}

double df(double x) {
    return 2*x;
}

double newton_method(double x0, double eps, int max_iter) {
    double x = x0;
    
    for (int i = 0; i < max_iter; ++i) {
        double fx = f(x);
        double dfx = df(x);
        
        // Проверка деления на ноль
        if (fabs(dfx) < 1e-12) {
            throw runtime_error("Производная близка к нулю. Метод не может продолжить.");
        }
        
        double x_new = x - fx / dfx;
        
        if (fabs(x_new - x) < eps) {
            cout << "Решение найдено за " << i + 1 << " итераций." << endl;
            return x_new;
        }
        
        x = x_new;
    }
    
    throw runtime_error("Превышено максимальное количество итераций.");
}

// Тесты с использованием Catch2
TEST_CASE("Метод Ньютона для функции", "[newton]") {
    SECTION("Корректное нахождение корня") {
        double root = newton_method(1.0, 1e-10, 100);
        REQUIRE(abs(root - sqrt(2)) < 1e-6);
        REQUIRE(abs(f(root)) < 1e-10);
    }
    
    SECTION("Разные начальные приближения") {
        double root1 = newton_method(1.0, 1e-8, 100);
        double root2 = newton_method(2.0, 1e-8, 100);
        REQUIRE(abs(root1 - root2) < 1e-8);
    }
    
    SECTION("Проверка на сходимость") {
        REQUIRE_NOTHROW(newton_method(1.5, 1e-12, 50));
    }
}

TEST_CASE("Обработка ошибок в методе Ньютона", "[newton][errors]") {
    SECTION("Деление на ноль при нулевой производной") {
        REQUIRE_THROWS_AS(newton_method(0.0, 1e-6, 100), runtime_error);
    }
    
    SECTION("Превышение максимального числа итераций") {
        REQUIRE_THROWS_AS(newton_method(1.0, 1e-20, 5), runtime_error);
    }
}

TEST_CASE("Граничные случаи", "[newton][boundary]") {
    SECTION("Очень высокая точность") {
        double root = newton_method(1.0, 1e-14, 1000);
        REQUIRE(abs(f(root)) < 1e-14);
    }
    
    SECTION("Низкая точность - быстрая сходимость") {
        double root = newton_method(1.0, 1e-2, 10);
        REQUIRE(abs(f(root)) < 1e-1);
    }
}