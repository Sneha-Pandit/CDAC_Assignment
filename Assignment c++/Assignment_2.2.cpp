//============================================================================
// Name        : 2.cpp
// Author      : Sneha
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
using namespace std;


double reorderCost(int qty, double unitPrice)
{
    return qty * unitPrice;
}


double reorderCost(double qty, double unitPrice)
{
    return qty * unitPrice;
}


double reorderCost(int qty, double unitPrice, double taxRate)
{
    double cost = qty * unitPrice;

    double tax = cost * taxRate / 100.0;

    return cost + tax;
}


double applyDiscount(double price,
                     double discountPercent = 10.0)
{
    double discount =
        price * discountPercent / 100.0;

    return price - discount;
}

int main()
{
    cout << fixed << setprecision(2);


    cout << "Integer quantity cost: "
         << reorderCost(10, 25.50)
         << endl;


    cout << "Fractional quantity cost: "
         << reorderCost(2.5, 25.50)
         << endl;


    cout << "Cost with tax: "
         << reorderCost(10, 25.50, 18.0)
         << endl;


    cout << "Discount with default 10%: "
         << applyDiscount(1000)
         << endl;


    cout << "Discount with 20%: "
         << applyDiscount(1000, 20.0)
         << endl;

    return 0;
}
