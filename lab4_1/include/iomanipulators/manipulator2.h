#ifndef MANIPULATOR2_H
#define MANIPULATOR2_H

#include <iostream>
#include <type_traits>
#include <utility>

// Базовый шаблон для определения типа возврата
template<typename T>
struct is_add_proxy : std::false_type {};

// Прокси для выполнения операции сложения - первый операнд
class AddProxyFirst {
public:
    explicit AddProxyFirst(std::ostream& os) : os_(os) {}

    // Обработка числовых типов - переходим к ожиданию второго операнда
    template<typename T>
    std::enable_if_t<std::is_arithmetic_v<T>, class AddProxySecond>
    operator<<(T value) {
        return AddProxySecond(os_, static_cast<long double>(value));
    }

    // Обработка нечисловых типов
    template<typename T>
    std::enable_if_t<!std::is_arithmetic_v<std::decay_t<T>>, AddProxyFirst&>
    operator<<(T&& val) {
        os_ << std::forward<T>(val);
        return *this;
    }

private:
    std::ostream& os_;
};

// Прокси для выполнения операции сложения - второй операнд
class AddProxySecond {
public:
    AddProxySecond(std::ostream& os, long double first)
        : os_(os), first_(first) {}

    // Обработка числовых типов - выполняем сложение и возвращаем поток
    template<typename T>
    std::enable_if_t<std::is_arithmetic_v<T>, std::ostream&>
    operator<<(T value) {
        os_ << (first_ + static_cast<long double>(value));
        return os_;
    }

    // Обработка нечисловых типов
    template<typename T>
    std::enable_if_t<!std::is_arithmetic_v<std::decay_t<T>>, AddProxySecond&>
    operator<<(T&& val) {
        os_ << std::forward<T>(val);
        return *this;
    }

private:
    std::ostream& os_;
    long double first_;
};

// Специализации для определения типов прокси
template<>
struct is_add_proxy<AddProxyFirst> : std::true_type {};

template<>
struct is_add_proxy<AddProxySecond> : std::true_type {};

// Тег манипулятора
struct AddTag {};
inline constexpr AddTag add{};

// Перегрузка оператора для std::ostream << add
inline AddProxyFirst operator<<(std::ostream& os, AddTag) {
    return AddProxyFirst(os);
}

#endif // MANIPULATOR2_H