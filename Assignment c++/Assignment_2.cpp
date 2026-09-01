//============================================================================
// Name        : Assignment_2.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================}
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Product
{
private:
    int productId;
    string name;
    double price;
    int quantity;

public:


    void acceptDetails()
    {
        cout << "Enter Product ID: ";
        cin >> productId;

        cin.ignore();

        cout << "Enter Product Name: ";
        getline(cin, name);

        cout << "Enter Price: ";
        cin >> price;

        cout << "Enter Quantity: ";
        cin >> quantity;
    }


    void displayDetails() const
    {
        cout << left
             << setw(8) << productId
             << setw(20) << name
             << right
             << setw(10) << fixed << setprecision(2) << price
             << setw(8) << quantity
             << setw(15) << totalValue();

        if (isLowStock(10))
        {
            cout << " <- LOW STOCK";
        }

        cout << endl;
    }


    double totalValue() const
    {
        return price * quantity;
    }


    bool isLowStock(int threshold) const
    {
        return quantity < threshold;
    }


    string getName() const
    {
        return name;
    }
};

int main()
{

    Product products[5];


    for (int i = 0; i < 5; i++)
    {
        cout << "\nEnter details for Product "
             << i + 1 << ":\n";

        products[i].acceptDetails();
    }


    cout << "\n===== INVENTORY REPORT =====\n";

    cout << left
         << setw(8) << "ID"
         << setw(20) << "Name"
         << right
         << setw(10) << "Price"
         << setw(8) << "Qty"
         << setw(15) << "Total Value"
         << endl;

    cout << string(61, '-') << endl;

    for (int i = 0; i < 5; i++)
    {
        products[i].displayDetails();
    }


    int highestIndex = 0;

    for (int i = 1; i < 5; i++)
    {
        if (products[i].totalValue() >
            products[highestIndex].totalValue())
        {
            highestIndex = i;
        }
    }

    cout << "\nHighest Value Product: "
         << products[highestIndex].getName()
         << " (Rs. "
         << fixed << setprecision(2)
         << products[highestIndex].totalValue()
         << ")" << endl;


    int threshold;

    cout << "\nEnter low-stock threshold: ";
    cin >> threshold;

    cout << "\nLow Stock Products:\n";

    bool found = false;

    for (int i = 0; i < 5; i++)
    {
        if (products[i].isLowStock(threshold))
        {
            cout << products[i].getName() << endl;
            found = true;
        }
    }

    if (!found)
    {
        cout << "No low-stock products." << endl;
    }

    return 0;
}
