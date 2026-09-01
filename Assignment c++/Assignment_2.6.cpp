//============================================================================
// Name        : 6.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================
#include <iostream>
#include <cstdlib>
using namespace std;


int main()
{
    int rows;
    int cols;


    cout << "Enter number of rows: ";
    cin >> rows;

    cout << "Enter number of columns: ";
    cin >> cols;



    if (rows <= 0 || cols <= 0)
    {
        cout << "Invalid map size." << endl;

        return 1;
    }



    int** map = new int*[rows];



    for (int i = 0; i < rows; i++)
    {
        map[i] = new int[cols];
    }

    srand(42);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            map[i][j] = rand() % 5;
        }
    }

    int counts[5] = {0, 0, 0, 0, 0};

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            counts[map[i][j]]++;
        }
    }


    cout << "\n===== GAME MAP ("
         << rows << " x "
         << cols << ") ====="
         << endl;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << map[i][j] << " ";
        }

        cout << endl;
    }


    cout << "\nLegend:"
         << endl;

    cout << "0 = Grass" << endl;
    cout << "1 = Water" << endl;
    cout << "2 = Mountain" << endl;
    cout << "3 = Forest" << endl;
    cout << "4 = Dungeon" << endl;



    cout << "\nTile Count:"
         << endl;

    cout << "Grass    : "
         << counts[0] << endl;

    cout << "Water    : "
         << counts[1] << endl;

    cout << "Mountain : "
         << counts[2] << endl;

    cout << "Forest   : "
         << counts[3] << endl;

    cout << "Dungeon  : "
         << counts[4] << endl;

    for (int i = 0; i < rows; i++)
    {
        delete[] map[i];
    }

    delete[] map;


    cout << "\nMemory released successfully."
         << endl;


    return 0;
}
