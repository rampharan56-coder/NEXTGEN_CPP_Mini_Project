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
    int tableID;
    string foodName;
    double price;

public:
    // Constructor
    Order(int table_id, std::string food, double price);

    

    // Getters
    int getTableID();
    string getFoodName();
    double getPrice();

    // Display one order
    void display();
};

#endif // ORDER_H

