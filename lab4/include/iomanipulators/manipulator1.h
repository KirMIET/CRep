#ifndef MANIPULATOR1_H
#define MANIPULATOR1_H

#include <iostream>
#include <string>

//Класс-манипулятор для вывода с добавлением [eol]\n
class EndmManipulator {
public:
    explicit EndmManipulator(const std::string& str = "") : content(str) {}
        
    friend std::ostream& operator<<(std::ostream& os, const EndmManipulator& manip);
    
private:
    std::string content;
};

// Функция-обертка для удобного использования
EndmManipulator endm(const std::string& str = "");

// Манипулятор-функция (альтернативный способ использования)
std::ostream& endm(std::ostream& os);

#endif // MANIPULATOR1_H