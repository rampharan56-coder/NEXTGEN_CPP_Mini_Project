#include "../include/OrderQueue.h"
#include <iostream>
using namespace std;

// Constructor
OrderQueue::OrderQueue()
{
    front = nullptr;
    rear = nullptr;
}

// Destructor
// Frees every Node and every Order
OrderQueue::~OrderQueue()
{
    Node *current = front;

    while (current != nullptr)
    {
        Node *nextNode = current->next;

        delete current->order;
        current->order = nullptr;

        delete current;
        current = nullptr;

        current = nextNode;
    }

    front = nullptr;
    rear = nullptr;

    cout << "\nAll memory has been freed." << endl;
    cout << "Program closed safely." << endl;
}

// ========================================================
// Add Order
// Queue operation: ENQUEUE
// ========================================================
void OrderQueue::enqueue(Order *newOrder)
{
    Node *newNode = new Node(newOrder);

    // If the queue is empty
    if (front == nullptr)
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }

    cout << "\nOrder added successfully." << endl;
}

// ========================================================
// Remove Order
// Queue operation: DEQUEUE
// ========================================================
void OrderQueue::dequeue()
{
    if (front == nullptr)
    {
        cout << "\nThe order line is empty." << endl;
        return;
    }

    Node *temp = front;

    cout << "\nServing Order #" << temp->order->getTableID() << endl;
    cout << "Food     : " << temp->order->getFoodName() << endl;
    cout << "Price    : $" << temp->order->getPrice() << endl;

    // Move front to the next node
    front = front->next;

    // If queue becomes empty
    if (front == nullptr)
    {
        rear = nullptr;
    }

    // Free memory
    delete temp->order;
    temp->order = nullptr;

    delete temp;
    temp = nullptr;

    cout << "Order served successfully." << endl;
}

// ========================================================
// View Current Order
// Queue operation: PEEK / FRONT
// ========================================================
void OrderQueue::peek()
{
    if (front == nullptr)
    {
        cout << "\nThe order line is empty." << endl;
        return;
    }

    cout << "\n========== Current Order to Serve ==========" << endl;
    front->order->display();
    cout << "============================================" << endl;
}

// ========================================================
// Display All Orders
// Linked List traversal
// ========================================================
void OrderQueue::display()
{
    if (front == nullptr)
    {
        cout << "\nThe order line is empty." << endl;
        return;
    }

    Node *current = front;
    int position = 1;

    cout << "\n========== Current Order Line ==========" << endl;

    while (current != nullptr)
    {
        cout << "\nPosition " << position << endl;
        cout << "----------------------------------------" << endl;

        current->order->display();

        current = current->next;
        position++;
    }

    cout << "========================================" << endl;
}

// ========================================================
// Search Order
// Search by Order ID
// ========================================================
void OrderQueue::search(int id)
{
    if (front == nullptr)
    {
        cout << "\nThe order line is empty." << endl;
        return;
    }

    Node *current = front;

    while (current != nullptr)
    {
        if (current->order->getTableID() == id)
        {
            cout << "\nOrder found." << endl;
            cout << "----------------------------------------" << endl;

            current->order->display();

            cout << "----------------------------------------" << endl;

            return;
        }

        current = current->next;
    }

    cout << "\nOrder #" << id << " was not found." << endl;
}

// ========================================================
// Selection Sort
// Sort orders by Order ID (O(N) swaps)
// ========================================================
void OrderQueue::sortByID(bool ascending)
{
    if (front == nullptr || front->next == nullptr)
    {
        cout << "\nNot enough orders to sort." << endl;
        return;
    }

    Node *i = front;

    while (i != nullptr)
    {
        Node *targetNode = i;
        Node *j = i->next;

        // Find the node with the minimum/maximum Order ID in the remaining list
        while (j != nullptr)
        {
            bool shouldSwap = ascending
                                  ? (j->order->getTableID() < targetNode->order->getTableID())
                                  : (j->order->getTableID() > targetNode->order->getTableID());

            if (shouldSwap)
            {
                targetNode = j;
            }
            j = j->next;
        }

        // Swap the Order pointers if a different node was selected
        if (targetNode != i)
        {
            Order *temp = i->order;
            i->order = targetNode->order;
            targetNode->order = temp;
        }

        i = i->next;
    }

    cout << "\nOrders sorted by Order ID ("
         << (ascending ? "Lowest First" : "Highest First")
         << ")." << endl;
}

// ========================================================
// Selection Sort
// Sort orders by Price (O(N) swaps)
// ========================================================
void OrderQueue::sortByPrice(bool ascending)
{
    if (front == nullptr || front->next == nullptr)
    {
        cout << "\nNot enough orders to sort." << endl;
        return;
    }

    Node *i = front;

    while (i != nullptr)
    {
        Node *targetNode = i;
        Node *j = i->next;

        // Find the node with the minimum/maximum Price in the remaining list
        while (j != nullptr)
        {
            bool shouldSwap = ascending
                                    ? (j->order->getPrice() < targetNode->order->getPrice())
                                    : (j->order->getPrice() > targetNode->order->getPrice());
                                    

            if (shouldSwap)
            {
                targetNode = j;
            }
            j = j->next;
        }

        // Swap the Order pointers if a different node was selected
        if (targetNode != i)
        {
            Order *temp = i->order;
            i->order = targetNode->order;
            targetNode->order = temp;
        }

        i = i->next;
    }

    cout << "\nOrders sorted by Price ("
         << (ascending ? "Lowest First" : "Highest First")
         << ")." << endl;
}

// ========================================================
// Default Sort (Backwards compatibility)
// ========================================================
void OrderQueue::sortOrders()
{
    sortByID(true);
}
