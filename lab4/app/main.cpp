#include <iostream>
#include <sstream>
#include "iomanipulators/manipulator1.h"
#include "iomanipulators/manipulator2.h"
#include "iomanipulators/manipulator3.h"

using namespace std;
using namespace iomanipulators;

void demonstrate_endm() {
    cout << "Hello world!" << endm;
}

void demonstrate_add() {
    cout << add << 32 << 32;
    cout << endl;
    cout << add << 3.2 << 3.2;
    cout << endl;
}

void demonstrate_sin(){
    cout << iomanipulators::sin << 5 << endl;
    cout << iomanipulators::sin << 0.0 << endl;
    cout << iomanipulators::sin << pi << endl;
    cout << iomanipulators::sin << 2*pi << endl;
}

int main() {
    cout << "Демонстрация манипуляторов" << endl;
    
    demonstrate_endm();
    demonstrate_add();
    demonstrate_sin();

    return 0;
}