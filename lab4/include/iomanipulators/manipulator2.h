#ifndef ADD_H
#define ADD_H

#include <iostream>
#include <type_traits>
#include <utility>

class AddProxy {
public:
    explicit AddProxy(std::ostream& os);

    // Обработка чисел (поддерживает int -> double и любые арифметические типы через приведение)
    AddProxy& operator<<(double value);

    // Шаблон — только для не-арифметических типов (строки, манипуляторы, объекты и т.д.)
    template <typename T,
              typename Decayed = typename std::decay<T>::type,
              typename = typename std::enable_if<!std::is_arithmetic<Decayed>::value>::type>
    AddProxy& operator<<(T&& val) {
        // просто перенаправляем в поток (например для std::endl, std::string, const char*, и т.п.)
        os_ << std::forward<T>(val);
        return *this;
    }

private:
    std::ostream& os_;
    bool hasFirst;
    long double first; // храним как long double для лучшей точности при суммах
};

// Функция-манипулятор (как std::hex)
AddProxy add(std::ostream& os);

// Перегрузка для std::cout << add
AddProxy operator<<(std::ostream& os, AddProxy (*f)(std::ostream&));

#endif // ADD_H
