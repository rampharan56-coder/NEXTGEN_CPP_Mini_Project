#include "../include/Order.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Order::Order(int table_id, string food, double p)
{
    tableID = table_id;
    foodName = food;
    price = p;
}

// Getters
int Order::getTableID()
{
    return tableID;
}

string Order::getFoodName()
{
    return foodName;
}

double Order::getPrice()
{
    return price;
}

// Display one order
void Order::display()
{
    cout << "Order ID     : " << tableID << endl;
    cout << "Food         : " << foodName << endl;
    cout << "Price        : $" << price << endl;
}

