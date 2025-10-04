#include <gtest/gtest.h>
#include <sstream>
#include "iomanipulators/manipulator1.h"

// Тест 1: Проверка вывода строки с манипулятором
TEST(EndmTest, BasicOutput) {
    std::stringstream ss;
    ss << endm("Hello");
    EXPECT_EQ(ss.str(), "Hello[eol]\n");
}

// Тест 2: Проверка пустой строки
TEST(EndmTest, EmptyString) {
    std::stringstream ss;
    ss << endm("");
    EXPECT_EQ(ss.str(), "[eol]\n");
}

// Тест 3: Проверка манипулятора без строки
TEST(EndmTest, ManipulatorAlone) {
    std::stringstream ss;
    ss << endm;
    EXPECT_EQ(ss.str(), "[eol]\n");
}

// Тест 4: Цепочка вызовов
TEST(EndmTest, ChainCalls) {
    std::stringstream ss;
    ss << "A" << endm << "B" << endm;
    EXPECT_EQ(ss.str(), "A[eol]\nB[eol]\n");
}