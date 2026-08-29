#include <iostream>
using namespace std;

int main()
{
    double temp[3][3];

    // Read temperatures
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> temp[i][j];
        }
    }

    // Display table
    cout << "Room1 Room2 Room3" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << "Floor " << i + 1 << " : ";

        for (int j = 0; j < 3; j++)
        {
            cout << temp[i][j] << " ";
        }

        cout << endl;
    }

    // Find hottest room
    double hottest = temp[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    int warningCount = 0;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (temp[i][j] > hottest)
            {
                hottest = temp[i][j];
                hotFloor = i;
                hotRoom = j;
            }

            if (temp[i][j] >= 30)
            {
                warningCount++;
            }
        }
    }

    // Find hottest floor
    double highestAverage = -999999;
    int hottestFloor = 0;

    for (int i = 0; i < 3; i++)
    {
        double sum = 0;

        for (int j = 0; j < 3; j++)
        {
            sum += temp[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage)
        {
            highestAverage = average;
            hottestFloor = i;
        }
    }

    cout << "Hottest Room : Floor "
         << hotFloor + 1
         << ", Room "
         << hotRoom + 1
         << " -> "
         << hottest << "C" << endl;

    cout << "Hottest Floor : Floor "
         << hottestFloor + 1
         << " (avg "
         << highestAverage
         << "C)" << endl;

    cout << "Rooms at WARNING or above : "
         << warningCount << endl;

    return 0;
}
