// #ifndef MANIPULATOR3_H
// #define MANIPULATOR3_H

// #include <ostream>
// #include <sstream>
// #include <string>
// #include <type_traits>

// namespace iomanipulators {

// // --- Теги для pi и выражений ---
// struct PiTag {
// };
// extern const PiTag pi;

// struct PiExpr {
//     double k;
//     constexpr explicit PiExpr(double kk) : k(kk) {}
// };

// inline PiExpr operator*(double k, const PiTag &) { return PiExpr(k); }
// inline PiExpr operator*(int k, const PiTag &) { return PiExpr(static_cast<double>(k)); }

// // Манипулятор sin 
// struct SinManipulator {};
// extern const SinManipulator sin;

// //Прокси для вывода
// class SinProxy {
// public:
//     explicit SinProxy(std::ostream &os) : os_(&os) {}

//     template<typename T>
//     std::enable_if_t<std::is_arithmetic_v<T>, std::ostream &>
//     operator<<(T value) {
//         std::ostringstream tmp;
//         tmp.copyfmt(*os_);
//         tmp << value;
//         std::string s = tmp.str();

//         if (s.find('.') == std::string::npos &&
//             s.find('e') == std::string::npos &&
//             s.find('E') == std::string::npos) {
//             s += ".0";
//         }
//         (*os_) << s;
//         return *os_;
//     }

//     std::ostream &operator<<(const PiTag &) {
//         (*os_) << "sin(pi)";
//         return *os_;
//     }

//     std::ostream &operator<<(const PiExpr &expr) {
//         (*os_) << "sin(" << expr.k << "*pi)";
//         return *os_;
//     }

// private:
//     std::ostream *os_;
// };

// inline SinProxy operator<<(std::ostream &os, const SinManipulator &) {
//     return SinProxy(os);
// }

// } 

// #endif // MANIPULATOR3_H
#ifndef MANIPULATOR3_H
#define MANIPULATOR3_H

#include <ostream>
#include <sstream>
#include <string>
#include <type_traits>

namespace iomanipulators {

// Теги для pi и выражений
struct PiTag {};
extern const PiTag pi;

struct PiExpr {
    double k;
    constexpr explicit PiExpr(double kk) : k(kk) {}
};

inline PiExpr operator*(double k, const PiTag &) { return PiExpr(k); }
inline PiExpr operator*(int k, const PiTag &) { return PiExpr(static_cast<double>(k)); }

// Манипулятор sin 
struct SinManipulator {};
extern const SinManipulator sin;

// Прокси для вывода
class SinProxy {
public:
    explicit SinProxy(std::ostream &os) : os_(&os) {}

    // Для чисел 
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

    // Для строк и символов 
    std::ostream &operator<<(const std::string &text) {
        (*os_) << text;
        return *os_;
    }

    std::ostream &operator<<(const char *text) {
        (*os_) << text;
        return *os_;
    }

    std::ostream &operator<<(char ch) {
        (*os_) << ch;
        return *os_;
    }

    // Для pi и выражений 
    std::ostream &operator<<(const PiTag &) {
        (*os_) << "sin(pi)";
        return *os_;
    }

    std::ostream &operator<<(const PiExpr &expr) {
        (*os_) << "sin(" << expr.k << "*pi)";
        return *os_;
    }

private:
    std::ostream *os_;
};

// Перегрузка оператора << для инициализации 
inline SinProxy operator<<(std::ostream &os, const SinManipulator &) {
    return SinProxy(os);
}

} // namespace iomanipulators

#endif // MANIPULATOR3_H
