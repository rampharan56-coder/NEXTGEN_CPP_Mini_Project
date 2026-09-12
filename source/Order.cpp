#include "../include/Order.h"
#include <iostream>

using namespace std;

// Constructor
Order::Order(int id, string customer, string food, double p)
{
    orderID = id;
    customerName = customer;
    foodName = food;
    price = p;
}

// Destructor
Order::~Order()
{
    // Nothing to free here because Order does not
    // directly allocate memory.
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

