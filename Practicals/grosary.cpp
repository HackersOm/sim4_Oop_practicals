#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int count,sum=0;
	cout<<"Enter No of products you want to buy:";
	cin>>count;
	string prod_name[count];
	int prod_price[count];
	for(int i=0;i<count;i++)
	{
		cout<<"Enter "<<i+1<<" product name:";
		cin>>prod_name[i];
		cout<<"Enter price for "<<i+1<<" product:";
		cin>>prod_price[i];
		sum+=prod_price[i];
	}
	cout<<"-------------------Bill----------------------"<<endl;
	cout<<"Product Name"<<"\t"<<"Product Price"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<prod_name[i]<<"\t\t"<<prod_price[i]<<"\n";
	}
	cout<<"----------------------------------------------"<<endl;
	cout<<"Total Sum="<<sum<<endl;
	cout<<"-------------------Formatted Bill-------------"<<endl;
	cout<<"Product Name"<<"\t"<<"Product Price"<<endl;
	for(int i=0;i<count;i++)
	{
		cout<<prod_name[i]<<"\t\t"<<setw(5)<<prod_price[i]<<"\n";
	}
	cout<<"----------------------------------------------"<<endl;
	cout<<"Total Bill="<<sum;
	return 0;	
}
