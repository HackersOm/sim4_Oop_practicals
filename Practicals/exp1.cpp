#include<iostream>
using namespace std;
int main()
{
	string name;
	char buffer[10];
	cout<<"Enter Name:"<<endl;
	//cin>>name;
	//getline(cin,name);
	//cin.get(buffer,5);
	cin.ignore(5)>>name;
    cout<<"Hello"<<"\t"<<name<<endl;
    //cout<<"Hello"<<"\t"<<buffer<<endl;
	return 0;
}
