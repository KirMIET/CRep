#include <iostream>
#include <sstream>
#include "iomanipulators/manipulator1.h"
#include "iomanipulators/manipulator2.h"

using namespace std;
void demonstrate_endm() {
    cout << "Hello world!" << endm;
}
void demonstrate_add() {
    cout << add << 32 << 32;
    cout << endl;
    cout << add << 3.2 << 3.2;
    cout << endl;
}
int main() {
    cout << "ДЕМОНСТРАЦИЯ МАНИПУЛЯТОРА endm" << endl;
    
    demonstrate_endm();
    demonstrate_add();
    
    return 0;
}