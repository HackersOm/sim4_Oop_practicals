#include<iostream>
// This program for printing arithmetical operation of two number 
using namespace std;
int main(){
    int a,b,res;

    cout<<"Enter Two number for Arithmetic Operation : "<<endl;
    cin>>a>>b;
    cout<<endl<<endl;
    res = a+b;
    cout<<"Addition of Two numbers :"<<res<<endl;
    res = a-b;
    cout<<"Substraction of Two numbers :"<<res<<endl;
    res = a*b;
    cout<<"Multiplication of Two numbers :"<<res<<endl;
    res = a/b;
    cout<<"Division of Two numbers :"<<res<<endl;
    res = a%b;
    cout<<"Modulo Division of Two numbers :"<<res<<endl;

    return 0;
}