#ifndef NODE_H
#define NODE_H
#include "Product.h"

class Node
{
    public:
        Node *next;
        Node *prev;

        Product data;
        Node();
        Node(class Product, Node*, Node*);

};

#endif // NODE_H
