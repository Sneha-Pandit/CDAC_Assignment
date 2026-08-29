//============================================================================
// Name        : 1.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cmath>

using namespace std;

// Compute RMS
double computeRMS(double* signal, int n)
{
    double sum = 0;

    for (int i = 0; i < n; i++)
    {
        double value = *(signal + i);

        sum += value * value;
    }

    return sqrt(sum / n);
}


// Normalise signal
void normalise(double* signal, int n)
{
    double maxAbs = 0;

    // Find maximum absolute value
    for (int i = 0; i < n; i++)
    {
        double value = fabs(*(signal + i));

        if (value > maxAbs)
        {
            maxAbs = value;
        }
    }

    // Divide each element
    if (maxAbs != 0)
    {
        for (int i = 0; i < n; i++)
        {
            *(signal + i) =
                *(signal + i) / maxAbs;
        }
    }
}


// Count zero crossings
int countZeroCrossings(double* signal, int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        double current = *(signal + i);
        double next = *(signal + i + 1);

        if ((current > 0 && next < 0) ||
            (current < 0 && next > 0))
        {
            count++;
        }
    }

    return count;
}


// Apply gain
void applyGain(double* signal, int n, double gainFactor)
{
    for (int i = 0; i < n; i++)
    {
        *(signal + i) =
            *(signal + i) * gainFactor;
    }
}


int main()
{
    double signal[] =
    {
        0.5, -1.2, 0.8,
        -0.3, 1.0, -0.9, 0.1
    };

    int n = 7;

    cout << "Before : ";

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    cout << "RMS : "
         << computeRMS(signal, n)
         << endl;

    cout << "Zero Crossings : "
         << countZeroCrossings(signal, n)
         << endl;

    normalise(signal, n);

    cout << "After Normalise : ";

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    applyGain(signal, n, 2.0);

    cout << "After Gain : ";

    for (int i = 0; i < n; i++)
    {
        cout << signal[i] << " ";
    }

    cout << endl;

    return 0;
}
