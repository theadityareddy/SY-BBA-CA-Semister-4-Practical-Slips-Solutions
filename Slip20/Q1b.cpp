#include<iostream>
#include<string.h>
using namespace std;

class Mobile
{
    private:
        char model[20];
        float price;
        float qnty;
    public:
        void accept()
        {
            cout<<"\nEnter model: ";
            cin>>model;
            cout<<"Enter price: ";
            cin>>price;
            cout<<"Enter quantity: ";
            cin>>qnty;
        }
        void sale(int n)
        {
            if(qnty == 0)
                cout<<"Stock empty";
            else if(n > qnty)
                cout<<"Insufficient stock";
            else
                qnty = qnty - n;
        }
        void purchase(int n) 
        {
            qnty = qnty + n;
        } 
        int compare(char str[])
        {
            if(strcmp(model, str) == 0)
                return 1;
            else
                return 0;
        }
};

int main()
{
    Mobile m1, m2;
    int choice, qty;
    char model[20];

    m1.accept();
    m2.accept();

    do
    {   
        cout<<"\n\n1) SALE: ";
        cout<<"\n2) PURCHASE: ";
        cout<<"\n3: EXIT";
        cout<<"\nEnter your choice: ";
        cin>>choice;

        switch(choice)
            {
                case 1: cout<<"Enter model to sell: ";
                        cin>>model;
                        if(m1.compare(model)==1)
                        {
                        cout<<"Enter quantity: ";
                        cin>>qty;
                        m1.sale(qty);
                        cout<<"SOLD: "<<qty<<" UNITS";
                        }
                        else if(m2.compare(model)==1)
                        {
                        cout<<"Enter quantity: ";
                        cin>>qty;
                        m2.sale(qty);
                        cout<<"SOLD: "<<qty<<" UNITS";
                        }
                    else 
                        cout<<"\nMODEL NOT AVALIABLE\n";
                        break;

                case 2: cout<<"Enter model to purchase: ";
                        cin>>model;
                        if(m1.compare(model)==1)
                        {
                        cout<<"Enter quantity: ";
                        cin>>qty;
                        m1.purchase(qty);
                        cout<<"SOLD: "<<qty<<" UNITS";
                        }
                        else if(m2.compare(model)==1)
                        {
                        cout<<"Enter quantity: ";
                        cin>>qty;
                        m2.purchase(qty);
                        cout<<"SOLD: "<<qty<<" UNITS";
                        }
                        else 
                            cout<<"\nMODEL NOT AVALIABLE\n";
            }   
    }while(choice != 3);

    return 0;
}
