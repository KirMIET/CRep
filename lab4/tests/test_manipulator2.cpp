#include <gtest/gtest.h>
#include <sstream>
#include "iomanipulators/manipulator2.h"

TEST(AddManipulatorTest, BasicAddition) {
    std::stringstream ss;
    ss << add << 5 << 3;
    EXPECT_EQ(ss.str(), "8");
}

TEST(AddManipulatorTest, NegativeNumbers) {
    std::stringstream ss;
    ss << add << -5 << 10;
    EXPECT_EQ(ss.str(), "5");
}

TEST(AddManipulatorTest, ZeroAddition) {
    std::stringstream ss;
    ss << add << 0 << 0;
    EXPECT_EQ(ss.str(), "0");
}

TEST(AddManipulatorTest, LargeNumbers) {
    std::stringstream ss;
    ss << add << 1000 << 2000;
    EXPECT_EQ(ss.str(), "3000");
}

TEST(AddManipulatorTest, ChainedUsage) {
    std::stringstream ss;
    ss << add << 1 << 2 << " and " << add << 3 << 4;
    EXPECT_EQ(ss.str(), "3 and 7");
}

TEST(AddManipulatorTest, InExpression) {
    std::stringstream ss;
    ss << "The sum is: " << add << 7 << 8 << "!";
    EXPECT_EQ(ss.str(), "The sum is: 15!");
}