#ifndef ORDER_H
#define ORDER_H

#include <string>
using namespace std;
// ============================================================
// Order Class
// Demonstrates OOP and dynamic memory
// ============================================================
class Order
{
private:
    int orderID;
    string customerName;
    string foodName;
    double price;

public:
    // Constructor
    Order(int id, std::string customer, std::string food, double price);

    // Destructor
    ~Order();

    // Getters
    int getOrderID();
    string getCustomerName();
    string getFoodName();
    double getPrice();

    // Display one order
    void display();
};

#endif // ORDER_H

