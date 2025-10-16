#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include <sstream>
#include <string>
#include <type_traits>

#include "iomanipulators/manipulator1.h"
#include "iomanipulators/manipulator2.h"
#include "iomanipulators/manipulator3.h"

using namespace iomanipulators;

TEST_CASE("iomanip::simple")
{
    std::stringstream s;
    s << "some text" << endm;
    CHECK(s.str() == "some text[eol]\n");
}

TEST_CASE("iomanip::two_operands")
{
    std::stringstream s;
    static_assert(!std::is_same_v<decltype(s << add), std::ostream&>);
    static_assert(!std::is_same_v<decltype(s << add << 48), std::ostream&>);
    static_assert(std::is_same_v<decltype(s << add << 48 << 56), std::ostream&>);

    SECTION("int")
    {
        s << add << 124 << 589 << " == " << 713;
        CHECK(s.str() == "713 == 713");
    }

    SECTION("string")
    {
        using namespace std::literals;
        s << add << "abc"s << "efg"s << " text";
        CHECK(s.str() == "abcefg text");
    }

    SECTION("double")
    {
        s << "get => " << add << 45.89 << 32.177 << " <=";
        CHECK(s.str() == "get => 78.067 <=");
    }
}

TEST_CASE("Sin manipulator basic functionality") {
    std::stringstream ss;

    SECTION("Output with integer number") {
        ss << iomanipulators::sin << 5;
        REQUIRE(ss.str() == "5.0");
    }

    SECTION("Output with floating point number") {
        ss << iomanipulators::sin << 3.14;
        REQUIRE(ss.str() == "3.14");
    }

    SECTION("Output with scientific notation number") {
        ss << iomanipulators::sin << 1.5e-3;
        REQUIRE(ss.str() == "0.0015"); 
    }

    SECTION("Output with pi tag") {
        ss << iomanipulators::sin << pi;
        REQUIRE(ss.str() == "sin(pi)");
    }

    SECTION("Output with pi expression") {
        ss << iomanipulators::sin << (2.5 * pi);
        REQUIRE(ss.str() == "sin(2.5*pi)");
    }

    SECTION("Output with integer pi expression") {
        ss << iomanipulators::sin << (3 * pi);
        REQUIRE(ss.str() == "sin(3*pi)");
    }
}

TEST_CASE("Sin manipulator in chain operations") {
    std::stringstream ss;

    SECTION("Multiple sin operations") {
        ss << "Start: " << iomanipulators::sin << 1 << ", Middle: " 
           << iomanipulators::sin << pi << ", End";
        REQUIRE(ss.str() == "Start: 1.0, Middle: sin(pi), End");
    }

    SECTION("Sin with different numeric types") {
        ss << iomanipulators::sin << 10 << " | " << iomanipulators::sin << 7.5;
        REQUIRE(ss.str() == "10.0 | 7.5");
    }
}
