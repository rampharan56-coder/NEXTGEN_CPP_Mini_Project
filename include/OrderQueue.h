#ifndef ORDER_QUEUE_H
#define ORDER_QUEUE_H

#include "Node.h"
#include "Order.h"

// ============================================================
// Queue Class
// Demonstrates:
// - Linked List
// - Queue
// - Dynamic Memory
// - Search
// - Selection Sort
// ============================================================
class OrderQueue
{
private:
    Node* front;
    Node* rear;

public:
    // Constructor
    OrderQueue();

    // Destructor
    // Frees every Node and every Order
    ~OrderQueue();

    // Add Order
    // Queue operation: ENQUEUE
    void enqueue(Order* newOrder);

    // Remove Order
    // Queue operation: DEQUEUE
    void dequeue();

    // View Current Order
    // Queue operation: PEEK / FRONT
    void peek();

    // Display All Orders
    // Linked List traversal
    void display();

    // Search Order
    // Search by Order ID
    void search(int table_id);

    // Selection Sort
    // Sort orders by Order ID (ascending or descending)
    void sortByID(bool ascending = true);

    // Sort orders by Price (ascending or descending)
    void sortByPrice(bool ascending = true);

    // Default sort by Order ID (ascending) for backwards compatibility
    void sortOrders();
};

#endif  //ORDER_QUEUE_H

