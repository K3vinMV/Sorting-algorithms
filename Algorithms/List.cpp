#include "List.h"

List::List()
{
    //ctor
}

List::List(Node *ptr, Node *ptr1)
{
    h=ptr;
    t=ptr1;
}

void List::initialize()
{
    h=nullptr;
    t=nullptr;
}

void List::insertAtBeginning(class Product data)
{
    Node *tmp=new Node(data,nullptr,nullptr);

    if(!h)
    {
        h=tmp;
        t=tmp;
    }else
    {
        tmp->next=h;
        h->prev=tmp;
        h=tmp;
    }
}

void List::insertAtEnd(class Product data)
{
    Node *tmp=new Node(data,nullptr,nullptr);
    tmp->data=data;

    if(!h)
    {
        h=tmp;
        t=tmp;
    }else if(t)
    {
        t->next=tmp;
        tmp->prev=t;
        t=tmp;
    }
}

void List::display()
{
    Node *aux=h;
    if(h)
    {
        while(aux)
        {
            cout<<"Name: "<<aux->data.name<<endl;
            cout<<"Price: "<<aux->data.price<<endl;
            cout<<"Id: "<<aux->data.id<<endl;
            cout<<"\n"<<endl;
            aux=aux->next;
        }
    }else
    {
        cout<<"List is empty"<<endl;
    }
}

void List::removeAll()
{
    while(h)
    {
        Node *aux=h;
        h=aux->next;
        delete aux;
    }
}

void List::isEmpty()
{
    if(h)
    {
        cout<<"List has data"<<endl;
    }else
    {
        cout<<"List is empty"<<endl;
    }
}

int List::Size()
{
    Node *aux=h;
    int i=0;
    if(h)
    {
        while(aux)
        {
            aux=aux->next;
            i++;
        }
    }
    return i;
}

void List::load()
{
    Product one; one.name = "Milk"; one.price = 3.5; one.id = 1;
    Product two; two.name = "Bread"; two.price = 5.0; two.id = 2;
    Product three; three.name = "Cookies"; three.price = 1.3; three.id = 3;
    Product four; four.name = "Juice"; four.price = 3.9; four.id = 4;
    Product five; five.name = "Water"; five.price = 2.9; five.id = 5;
    Product six; six.name = "Meat"; six.price = 35.0; six.id = 6;
    Product seven; seven.name = "Apple"; seven.price = 1.0; seven.id = 7;
    Product eight; eight.name = "Cereal"; eight.price = 6.0; eight.id = 8;

    insertAtBeginning(one);
    insertAtBeginning(two);
    insertAtBeginning(three);
    insertAtBeginning(four);
    insertAtBeginning(five);
    insertAtBeginning(six);
    insertAtBeginning(seven);
    insertAtBeginning(eight);

}

void List::bubble_sort()
{
    if (h == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }
    bool swapped;
    Node* aux;
    Node* lastSorted = nullptr;

    do {
        swapped = false;
        aux = h;

        while (aux->next != lastSorted) {
            if (aux->data.price > aux->next->data.price) {
                Product temp = aux->data;
                aux->data = aux->next->data;
                aux->next->data = temp;
                swapped = true;
            }
            aux = aux->next;
        }
        lastSorted = aux;
    } while (swapped);
}

void List::insert_sort()
{
    Product tmp;
    Node *aux=h;
    Node *key=aux;

    if(h)
    {
       while(aux->next)
       {
           aux=aux->next;
           key=aux;
           while(key->prev)
           {
               if(key->prev->data.price<key->data.price)
               {
                    tmp=key->data;
                    key->data=key->prev->data;
                    key->prev->data=tmp;
               }
            key=key->prev;
           }

       }
    }else
    {
        cout<<"La lista no tiene elementos"<<endl;
    }
}

void List::select_sort()
{
    Product tmp;
    Node *aux=h;
    Node *Iterator;
    Node *maxNode;

    if(h)
    {
        while(aux->next)
        {
            maxNode=aux;
            Iterator=aux->next;
            while(Iterator!=nullptr)
            {
                if(Iterator->data.price>maxNode->data.price)
                {
                    maxNode=Iterator;
                }
                Iterator=Iterator->next;
            }
            if(maxNode->data.price>aux->data.price)
            {
                tmp=maxNode->data;
                maxNode->data=aux->data;
                aux->data=tmp;

            }
            aux=aux->next;
        }
    }else
    {
        cout<<"List is empty"<<endl;
    }
}

void List::shell_sort()
{
    if (h == nullptr)
        {
        cout << "List is empty" << endl;
        return;
        }

        // Calculate the length of the list
        int length = 0;
        Node* current = h;
        while (current != nullptr)
        {
            length++;
            current = current->next;
        }

        // Start with a large gap, then reduce the gap
        for (int gap = length / 2; gap > 0; gap /= 2)
            {
            for (int i = gap; i < length; i++)
            {
                Node* right = h;
                for (int k = 0; k < i; k++)
                {
                    right = right->next;
                }
                Product temp = right->data;

                int j;
                Node* left = h;
                for (j = i; j >= gap; j -= gap)
                    {
                    Node* leftNext = h;
                    for (int k = 0; k < j - gap; k++)
                    {
                        leftNext = leftNext->next;
                    }
                    if (leftNext->data.price <= temp.price)
                    {
                        break;
                    }
                    right->data = leftNext->data;
                    right = leftNext;
                }
                right->data = temp;
            }
        }
}

void List::merge_sort(int Size, List *L)
{
    List *right=new List;
    List *left=new List;
    Node *aux=L->h;

    int middle=Size/2;
    int difference=Size%2;
    int i,j;

    if(L->Size()>1)
    {
        i=0;
        while(i<middle)
        {
            left->insertAtBeginning(aux->data);
            i++;
            aux=aux->next;
        }
        j=0;
        while(j<middle+difference)
        {
            right->insertAtBeginning(aux->data);
            j++;
            aux=aux->next;

        }
        merge_sort(left->Size(),left);
        merge_sort(right->Size(),right);

        Node *lt=left->h;   // 'lt' for left part
        Node *rt=right->h;  // 'rt' for right part
        aux=L->h;

        while(lt && rt)
        {
            if(lt->data.price < rt->data.price)
            {
                aux->data=lt->data;
                lt=lt->next;
                aux=aux->next;
            }else
            {
                aux->data=rt->data;
                rt=rt->next;
                aux=aux->next;
            }
        }
        if(lt)
        {
            while(lt)
            {
                aux->data=lt->data;
                lt=lt->next;
                aux=aux->next;
            }
        }else
        {
            while(rt)
            {
                aux->data=rt->data;
                rt=rt->next;
                aux=aux->next;
            }
        }
    }
}

void List::quick_sort(List *l)
{
    Node *pivot;
    Node *pivotCopy;
    Node *aux;

    List *upper = new List;
    List *lower = new List;

    if (l->h) {
        pivot = l->h;
        pivotCopy = new Node(l->h->data, nullptr, nullptr);
        aux = l->h->next;
        while (aux) {
            if (aux->data.price < pivot->data.price) {
                lower->insertAtBeginning(aux->data);
            } else {
                upper->insertAtEnd(aux->data);
            }
            aux = aux->next;
        }
        quick_sort(lower);
        quick_sort(upper);

        aux = l->h;
        Node *lt = lower->h;  // 'lt' for left part
        while (lt) {
            aux->data = lt->data;
            aux = aux->next;
            lt = lt->next;
        }
        {
            aux->data = pivotCopy->data;
            aux = aux->next;
        }
        Node *rt = upper->h;  // 'rt' for right part
        while (rt) {
            aux->data = rt->data;
            aux = aux->next;
            rt = rt->next;
        }
    }
}
