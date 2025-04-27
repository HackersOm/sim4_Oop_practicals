#include<iostream>
// This is program for printing the table of give number 
using namespace std;
int main(){
    int no;
    cout<<"Enter no. :-";
    cin>>no;
    for(int i = 1 ;i<=10;i++){
        cout<<no<<" X "<<i<<" = "<<no*i<<endl;

    }
    return 0;
}