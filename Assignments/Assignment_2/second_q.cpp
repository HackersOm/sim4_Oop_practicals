#include<iostream>
// This is program for finding the largest number between three
using namespace std;

int main(){
    int no1,no2,no3;
    cout<<"Enter Three Numbers: "<<endl;
    cin>>no1>>no2>>no3;

    if(no1>no2 && no1>no3){
        cout<<"First Number Entered is greatest"<<endl;
    }
    else if (no2>no1 && no2>no3){
        cout<<"Second Number Entered is greatest "<<endl;

    }
    else{
        cout<<"Third Number Entered is greatest "<<endl;

    }
    return 0;
}