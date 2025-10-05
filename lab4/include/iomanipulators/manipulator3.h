#ifndef MANIPULATOR3_H
#define MANIPULATOR3_H

#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>
#include <cmath>

namespace iomanipulators {

constexpr double MANIP_PI_VALUE = 3.14159265358979323846;

// --- Теги для pi и выражений ---
struct PiTag {
    constexpr operator double() const noexcept { return MANIP_PI_VALUE; }
};
extern const PiTag pi;

struct PiExpr {
    double k;
    constexpr explicit PiExpr(double kk) : k(kk) {}
    constexpr operator double() const noexcept { return k * MANIP_PI_VALUE; }
};

inline PiExpr operator*(double k, const PiTag &) { return PiExpr(k); }
inline PiExpr operator*(int k, const PiTag &) { return PiExpr(static_cast<double>(k)); }

// --- Манипулятор sin ---
struct SinManipulator {};
extern const SinManipulator sin;

// --- Прокси для вывода ---
class SinProxy {
public:
    explicit SinProxy(std::ostream &os) : os_(&os) {}

    template<typename T>
    std::enable_if_t<std::is_arithmetic_v<T>, std::ostream &>
    operator<<(T value) {
        std::ostringstream tmp;
        tmp.copyfmt(*os_);
        tmp << value;
        std::string s = tmp.str();

        if (s.find('.') == std::string::npos &&
            s.find('e') == std::string::npos &&
            s.find('E') == std::string::npos) {
            s += ".0";
        }
        (*os_) << s;
        return *os_;
    }

    std::ostream &operator<<(const PiTag &p) {
        double val = static_cast<double>(p);
        (*os_) << "sin(pi)";
        return *os_;
    }

    std::ostream &operator<<(const PiExpr &expr) {
        double val = static_cast<double>(expr);
        (*os_) << "sin(" << expr.k << "*pi)";
        return *os_;
    }

private:
    std::ostream *os_;
};

inline SinProxy operator<<(std::ostream &os, const SinManipulator &) {
    return SinProxy(os);
}

} // namespace iomanipulators

#endif // MANIPULATOR3_H
