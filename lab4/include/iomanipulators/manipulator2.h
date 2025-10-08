#ifndef MANIPULATOR2_H
#define MANIPULATOR2_H

#include <iostream>
#include <type_traits>
#include <utility>

class AddProxy {
public:
    explicit AddProxy(std::ostream& os);

    // Обработка чисел 
    AddProxy& operator<<(double value);

    // Шаблон — только для не-арифметических типов (строки, манипуляторы, объекты и т.д.)
    template <typename T,
              typename Decayed = typename std::decay<T>::type,
              typename = typename std::enable_if<!std::is_arithmetic<Decayed>::value>::type>
    AddProxy& operator<<(T&& val) {
        os_ << std::forward<T>(val);
        return *this;
    }

private:
    std::ostream& os_;
    bool hasFirst;
    long double first; // храним как long double для лучшей точности при суммах
};

// Функция-манипулятор 
AddProxy add(std::ostream& os);

// Перегрузка для std::cout << add
AddProxy operator<<(std::ostream& os, AddProxy (*f)(std::ostream&));

#endif // MANIPULATOR2_H
