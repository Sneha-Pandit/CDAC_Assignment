//============================================================================
// Name        : 2.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================


#include<iostream>
#include<iomanip>

using namespace std;

int main() {
    cout << "========== PROBLEM 2: SENSOR LOG BUFFER ==========" << endl;

    // STEP 1: Accept N from user
    int N;

    cout << "Enter number of readings (1-100): ";
    cin >> N;

    // Validate N
    if (N < 1 || N > 100) {
        cout << "Invalid! N must be between 1 and 100" << endl;
        return 1;
    }

    // STEP 2: Create array and read N values
    double readings[100];

    cout << "Enter " << N << " temperature readings:" << endl;
    for (int i = 0; i < N; i++) {
        cout << "Reading " << (i + 1) << ": ";
        cin >> readings[i];
    }

    cout << "\nReadings entered : " << N << endl;

    // STEP 3: Print valid readings (skip errors < 0 using continue)
    cout << "Valid readings : ";
    int validCount = 0;
    int errorCount = 0;

    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            errorCount++;
            continue;  // SKIP this one, go to next iteration
        }

        cout << fixed << setprecision(1) << readings[i] << " ";
        validCount++;
    }

    cout << endl;
    cout << "Skipped (errors) : " << errorCount << endl;

    // STEP 4: Find first CRITICAL reading (>=45°C) using break
    cout << "First CRITICAL : ";
    bool foundCritical = false;

    for (int i = 0; i < N; i++) {
        if (readings[i] >= 45) {
            cout << "Index " << i << " → " << fixed << setprecision(1)
                 << readings[i] << "°C" << endl;
            foundCritical = true;
            break;  // STOP loop, found it!
        }
    }

    if (!foundCritical) {
        cout << "Not found" << endl;
    }

    // STEP 5: Calculate min, max, average in ONE loop pass
    double minTemp = readings[0];
    double maxTemp = readings[0];
    double sum = 0;

    for (int i = 0; i < N; i++) {
        if (readings[i] < minTemp) {
            minTemp = readings[i];
        }

        if (readings[i] > maxTemp) {
            maxTemp = readings[i];
        }

        sum += readings[i];
    }

    double average = sum / N;

    cout << "Min : " << fixed << setprecision(1) << minTemp << "°C "
         << "Max : " << maxTemp << "°C "
         << "Avg : " << setprecision(2) << average << "°C" << endl;

    // STEP 6: Count readings per category
    int normalCount = 0;      // 0-29°C
    int warningCount = 0;     // 30-44°C
    int criticalCount = 0;    // 45-59°C
    int shutdownCount = 0;    // >=60°C

    for (int i = 0; i < N; i++) {
        if (readings[i] < 0) {
            continue;
        }
        else if (readings[i] >= 0 && readings[i] <= 29) {
            normalCount++;
        }
        else if (readings[i] >= 30 && readings[i] <= 44) {
            warningCount++;
        }
        else if (readings[i] >= 45 && readings[i] <= 59) {
            criticalCount++;
        }
        else {
            shutdownCount++;
        }
    }

    cout << "Normal:" << normalCount << " Warning:" << warningCount
         << " Critical:" << criticalCount << " Shutdown:" << shutdownCount << endl;

    return 0;
}

