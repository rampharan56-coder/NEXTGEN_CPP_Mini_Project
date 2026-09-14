#include "../include/Order.h"
#include <iostream>
#include <string>
using namespace std;

// Constructor
Order::Order(int id, string customer, string food, double p)
{
    orderID = id;
    customerName = customer;
    foodName = food;
    price = p;
}



// Getters
int Order::getOrderID()
{
    return orderID;
}

string Order::getCustomerName()
{
    return customerName;
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
    cout << "Order ID     : " << orderID << endl;
    cout << "Customer     : " << customerName << endl;
    cout << "Food         : " << foodName << endl;
    cout << "Price        : $" << price << endl;
}

