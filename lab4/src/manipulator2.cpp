#include "iomanipulators/manipulator2.h"

AddProxy::AddProxy(std::ostream& os) : os_(os), hasFirst(false), first(0.0L) {}

AddProxy& AddProxy::operator<<(double value) {
    if (!hasFirst) {
        first = static_cast<long double>(value);
        hasFirst = true;
    } else {
        long double sum = first + static_cast<long double>(value);

        // Выводим сумму в поток
        os_ << sum;

        hasFirst = false; // сброс для повторного использования
    }
    return *this;
}

AddProxy add(std::ostream& os) {
    return AddProxy(os);
}

AddProxy operator<<(std::ostream& os, AddProxy (*f)(std::ostream&)) {
    return f(os);
}
