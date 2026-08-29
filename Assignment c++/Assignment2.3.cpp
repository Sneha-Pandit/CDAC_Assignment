//============================================================================
// Name        : 2.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main()
{
    int statusReg = 0b10110001;
    int controlReg = 0b00000000;
    int dataReg = 0b11001010;

    // Pointer to const int
    const int* regPtr1 = &statusReg;

    cout << "Status Register : "
         << *regPtr1 << endl;

    // *regPtr1 = 10;
    // ERROR: cannot modify value through pointer-to-const

    regPtr1 = &dataReg;
    // This is allowed because pointer itself is not const.


    // Const pointer to int
    int* const regPtr2 = &controlReg;

    *regPtr2 = 100;

    cout << "Control Register : "
         << *regPtr2 << endl;

    // regPtr2 = &dataReg;
    // ERROR: cannot change the address
    // because regPtr2 is a const pointer.


    // Const pointer to const int
    const int* const regPtr3 = &statusReg;

    cout << "Status Register : "
         << *regPtr3 << endl;

    // *regPtr3 = 20;
    // ERROR: cannot modify the value

    // regPtr3 = &dataReg;
    // ERROR: cannot change the pointer

    return 0;
}
