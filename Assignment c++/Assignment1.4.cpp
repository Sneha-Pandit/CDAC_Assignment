//============================================================================
// Name        : 4.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <cstdlib>

using namespace std;

int main(int argc, char* argv[])
{
    // Check arguments
    if (argc != 4)
    {
        cout << "Usage : ./sensor_monitor "
             << "<warn_threshold> "
             << "<critical_threshold> "
             << "<num_readings>" << endl;

        cout << "Error : Missing arguments." << endl;

        return 1;
    }

    // Convert command-line arguments
    int warn = stoi(argv[1]);
    int critical = stoi(argv[2]);
    int n = stoi(argv[3]);

    // Validate thresholds
    if (warn >= critical)
    {
        cout << "Error : Warning threshold must be "
             << "less than critical threshold." << endl;

        return 1;
    }

    // Validate number of readings
    if (n < 1 || n > 500)
    {
        cout << "Error : Number of readings must "
             << "be between 1 and 500." << endl;

        return 1;
    }

    int normal = 0;
    int warning = 0;
    int criticalCount = 0;
    int shutdown = 0;

    // Generate and classify readings
    for (int i = 0; i < n; i++)
    {
        int temperature = rand() % 70;

        if (temperature < warn)
        {
            normal++;
        }
        else if (temperature < critical)
        {
            warning++;
        }
        else if (temperature < 60)
        {
            criticalCount++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << "Config : Warn="
         << warn
         << "C Critical="
         << critical
         << "C Readings="
         << n << endl;

    cout << "Results : Normal:"
         << normal
         << " Warning:"
         << warning
         << " Critical:"
         << criticalCount
         << " Shutdown:"
         << shutdown << endl;

    return 0;
}
