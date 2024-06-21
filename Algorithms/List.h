#ifndef LIST_H
#define LIST_H
#include <iostream>
#include "Product.h"
#include "Node.h"

using namespace std;

class List
{
    public:
        Node *h;
        Node *t;

        List();
        List(Node*, Node*);

        void initialize();
        void insertAtBeginning(class Product);
        void insertAtEnd(class Product);
        void display();
        void removeAll();
        void isEmpty();
        int Size();
        void load();
        void bubble_sort();
        void insert_sort();
        void select_sort();
        void shell_sort();
        void merge_sort(int, List*);
        void quick_sort(List*);
};

#endif // LIST_H
