#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
    int size,sum=0;
    cout<<"Enter How much product you want to buy:";
    cin>>size;
    string prod_list[size];
    int prod_price[size];
    for(int i=0;i<size;i++)
    {
        cout<<"Enter "<<i+1<<" product name:";
        cin>>prod_list[i];
        cout<<"Enter "<<i+1<<" product price:";
        cin>>prod_price[i];
        sum+=prod_price[i];
    } 
    cout<<"--------------Normal Bill-------------"<<endl;
    cout<<"Product Name"<<"\t"<<"Product Price"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<prod_list[i]<<"\t\t"<<prod_price[i]<<" Rs"<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<"Total Sum="<<sum<<endl;
    cout<<"---------------Formatted Bill----------"<<endl;
    cout<<"Product Name"<<"\t"<<setw(5)<<"Product Price"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<prod_list[i]<<"\t\t"<<prod_price[i]<<" Rs"<<endl;
    }
    cout<<"---------------------------------------------"<<endl;
    cout<<"Total Bill="<<sum;
    return 0;
}