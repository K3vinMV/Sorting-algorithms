#include <iostream>
#include "Product.h"
#include "List.h"
#include "Node.h"

using namespace std;

void pause();

int main()
{
    List *lis=new List();

    int opt;
    Product data;

    do
    {
        system("cls");
        cout<<"----------------SORTING ALGORITHMS------------------"<<endl;
        cout<<"1.-Iinitialize"<<endl;
        cout<<"2.-Insert at beginning"<<endl;
        cout<<"3.-Insert at end"<<endl;
        cout<<"4.-Remove all"<<endl;
        cout<<"5.-Is empty?"<<endl;
        cout<<"6.-Size"<<endl;
        cout<<"7.-Display"<<endl;
        cout<<"8.-Load"<<endl;
        cout<<"9.-Bubble Sort"<<endl;
        cout<<"10.-Shell Sort"<<endl;
        cout<<"11.-Insert Sort"<<endl;
        cout<<"12.-Select Sort"<<endl;
        cout<<"13.-Quick Sort"<<endl;
        cout<<"14.-Merge Sort"<<endl;
        cout<<"15.-Exit"<<endl;
        cout<<"-------------------------------------------------------------"<<endl;
        cout<<"Please enter an option: "<<endl;
        cin>>opt;

        switch(opt)
        {
        case 1:
            system("cls");
            cout<<"-------INITIALIZE-------"<<endl;
            cout<<"List started"<<endl;
            lis->initialize();
            pause();
            break;

        case 2:
            system("cls");
            cout<<"-------INSERT AT BEGINNING-------"<<endl;
            cout<<"Insert name: "<<endl;
            cin>>data.name;
            cout<<"Insert price: "<<endl;
            cin>>data.price;
            cout<<"Insert id: "<<endl;
            cin>>data.id;
            lis->insertAtBeginning(Product(data));
            pause();
            break;

        case 3:
            system("cls");
            cout<<"--------INSERT AT END--------"<<endl;
            cout<<"Insert name: "<<endl;
            cin>>data.name;
            cout<<"Insert price: "<<endl;
            cin>>data.price;
            cout<<"Insert id: "<<endl;
            cin>>data.id;
            lis->insertAtEnd(Product(data));
            pause();
            break;

        case 4:
            system("cls");
            int rmv;
            cout<<"-------REMOVE ALL-------"<<endl;
            cout<<"Are you sure you want to delete everything? "<<endl;
            cout<<"1.Yes "<<endl;
            cout<<"2.No"<<endl;
            cin>>rmv;
            if(rmv==1)
            {
                cout<<"Ereasing..."<<endl;
                lis->removeAll();
            }else
            {
                cout<<"Returning..."<<endl;
            }
            pause();
            break;

        case 5:
            system("cls");
            cout<<"-------IS EMPTY?-------"<<endl;
            lis->isEmpty();
            pause();
            break;

        case 6:
            system("cls");
            int i;
            cout<<"-------SIZE-------"<<endl;
            i=(lis->Size());
            cout<<"The total size of the list is: "<<i<<endl;
            pause();
            break;

        case 7:
            system("cls");
            cout<<"-------DISPLAY EVERYTHING-------"<<endl;
            lis->display();
            pause();
            break;

        case 8:
            system("cls");
            cout<<"--------LOAD--------"<<endl;
            lis->load();
            cout<<"The data has been loaded"<<endl;
            pause();
            break;

        case 9:
            system("cls");
            cout<<"--------BUBBLE SORT--------"<<endl;
            lis->bubble_sort();
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 10:
            system("cls");
            cout<<"--------SHELL SORT--------"<<endl;
            lis->shell_sort();
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 11:
            system("cls");
            cout<<"--------INSERT SORT--------"<<endl;
            lis->insert_sort();
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 12:
            system("cls");
            cout<<"--------SELECT SORT--------"<<endl;
            lis->select_sort();
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 13:
            system("cls");
            cout<<"--------QUICK SORT--------"<<endl;
            lis->quick_sort(lis);
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 14:
            system("cls");
            cout<<"--------MERGE SORT--------"<<endl;
            lis->merge_sort(lis->Size(),lis);
            cout<<"The products have been sorted"<<endl;
            pause();
            break;

        case 15:
            system("cls");
            cout<<"Quitting..."<<endl;
            break;

        default:
            system("cls");
            cout<<"Not a valid option"<<endl;
            break;
        }

    }while(opt!=15);

    return 0;
}

void pause()
{
    cout<<"Press any key to continue..."<<endl;
    getwchar();
    getwchar();
}
