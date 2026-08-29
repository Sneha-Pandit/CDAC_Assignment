//============================================================================
// Name        : Assignment2.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

// Call by Value
void resetSensorPairV1(int reading1, int reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

// Call by Reference
void resetSensorPairV2(int& reading1, int& reading2)
{
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

// Call by Pointer
void resetSensorPairV3(int* reading1, int* reading2)
{
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main()
{
    int A = 55;
    int B = 12;

    /*
       V1 fails because function receives copies.
       Changes happen only to the local copies.
       The original variables A and B are not changed.
       Therefore call by value cannot swap the original values.
    */

    cout << "--- V1: Call by Value ---" << endl;

    cout << "Before : A=" << A
         << " B=" << B << endl;

    resetSensorPairV1(A, B);

    cout << "After : A=" << A
         << " B=" << B << endl;


    cout << "--- V2: Call by Reference ---" << endl;

    cout << "Before : A=" << A
         << " B=" << B << endl;

    resetSensorPairV2(A, B);

    cout << "After : A=" << A
         << " B=" << B << endl;


    cout << "--- V3: Call by Pointer ---" << endl;

    cout << "Before : A=" << A
         << " B=" << B << endl;

    resetSensorPairV3(&A, &B);

    cout << "After : A=" << A
         << " B=" << B << endl;

    return 0;
}
