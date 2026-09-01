//============================================================================
// Name        : 5.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <algorithm>
using namespace std;

namespace Physics
{
    double clamp(double val, double min, double max)
    {
        return std::max(min, std::min(val, max));
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


namespace GameMath
{
    int clamp(int val, int min, int max)
    {
        return std::max(min, std::min(val, max));
    }

    double lerp(double a, double b, double t)
    {
        return a + (b - a) * t;
    }
}


int main()
{

    cout << "Physics clamp: "
         << Physics::clamp(15.5, 0.0, 10.0)
         << endl;

    cout << "GameMath clamp: "
         << GameMath::clamp(120, 0, 100)
         << endl;

    cout << "Physics lerp: "
         << Physics::lerp(0.0, 100.0, 0.25)
         << endl;

    cout << "GameMath lerp: "
         << GameMath::lerp(0.0, 100.0, 0.75)
         << endl;

    {
        using namespace Physics;

        cout << "Limited scope clamp: "
             << clamp(15.0, 0.0, 10.0)
             << endl;
    }


    return 0;
}
