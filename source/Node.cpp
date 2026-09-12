#include "../include/Node.h"

// Constructor
Node::Node(Order* newOrder)
{
    order = newOrder;
    next = nullptr;
}

