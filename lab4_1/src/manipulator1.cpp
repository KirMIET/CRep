#include "iomanipulators/manipulator1.h"

std::ostream& operator<<(std::ostream& os, const EndmManipulator& manip) {
    if (!manip.content.empty()) {
        os << manip.content;
    }
    return os << "[eol]\n";
}

// Реализация функции-обертки
EndmManipulator endm(const std::string& str) {
    return EndmManipulator(str);
}

// Реализация манипулятора-функции
std::ostream& endm(std::ostream& os) {
    return os << "[eol]\n";
}