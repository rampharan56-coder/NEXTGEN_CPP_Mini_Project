#ifndef ORDER_H
#define ORDER_H

#include <string>

// ============================================================
// Order Class
// Demonstrates OOP and dynamic memory
// ============================================================
class Order
{
private:
    int orderID;
    std::string customerName;
    std::string foodName;
    double price;

public:
    // Constructor
    Order(int id, std::string customer, std::string food, double price);

    // Destructor
    ~Order();

    // Getters
    int getOrderID();
    std::string getCustomerName();
    std::string getFoodName();
    double getPrice();

    // Display one order
    void display();
};

#endif // ORDER_H

