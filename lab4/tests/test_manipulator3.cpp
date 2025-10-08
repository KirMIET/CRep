#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include <sstream>
#include "iomanipulators/manipulator3.h"

using namespace iomanipulators;

TEST(SinManipulatorTest, ConvertsIntToDouble) {
    std::ostringstream oss;
    oss << iomanipulators::sin << 0;
    EXPECT_EQ(oss.str(), "0.0");
}

TEST(SinManipulatorTest, ConvertsDoubleToDouble) {
    std::ostringstream oss;
    oss << iomanipulators::sin << 0.0;
    EXPECT_EQ(oss.str(), "0.0");
}

TEST(SinManipulatorTest, OnePi) {
    std::ostringstream oss;
    oss << iomanipulators::sin << pi;
    EXPECT_EQ(oss.str(), "sin(pi)");
}

TEST(SinManipulatorTest, MorePi) {
    std::ostringstream oss;
    oss << iomanipulators::sin << 2*pi;
    EXPECT_EQ(oss.str(), "sin(2*pi)");
}

TEST(SinManipulatorTest, DoublePi) {
    std::ostringstream oss;
    oss << iomanipulators::sin << 2.5*pi;
    EXPECT_EQ(oss.str(), "sin(2.5*pi)");
}