#ifndef NODE_H
#define NODE_H

#include "Order.h"

// ============================================================
// Node Class
// Used to build our own linked list
// ============================================================
class Node
{
public:
    Order* order;
    Node* next;

    // Constructor
    Node(Order* newOrder);
};

#endif  //NODE_H

