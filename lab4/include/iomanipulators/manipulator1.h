#ifndef ENDM_MANIPULATOR_HPP
#define ENDM_MANIPULATOR_HPP

#include <iostream>
#include <string>

//Класс-манипулятор для вывода с добавлением [eol]\n
class EndmManipulator {
public:
    // Конструктор принимает строку для вывода
    explicit EndmManipulator(const std::string& str = "") : content(str) {}
    
    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const EndmManipulator& manip);
    
private:
    std::string content;
};

// Функция-обертка для удобного использования
EndmManipulator endm(const std::string& str = "");

// Манипулятор-функция (альтернативный способ использования)
std::ostream& endm(std::ostream& os);

#endif // ENDM_MANIPULATOR_HPP