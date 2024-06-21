#include "Node.h"
#include "Product.h"

Node::Node()
{
    Product data;
    next=nullptr;
    prev=nullptr;
    //ctor
}
Node::Node(class Product data, Node *next, Node *prev)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
}
