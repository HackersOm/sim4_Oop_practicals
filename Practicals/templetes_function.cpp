#include <iostream>

using namespace std;


template <typename T>
// T add(T num1,T num2)
// {
//     return num1+num2;
// }

T compare(T num1,T num2)
{
    return (num1 > num2)?num1:num2;
}

int main()
{
    // cout<<add(5,7)<<endl;
    // cout<<add(1.5,1.5)<<endl;
    int n1,n2;
    float f1,f2;
    cout<<"Enter 1st Integer:";
    cin>>n1;
    cout<<"Enter 2nd Integer:";
    cin>>n2;
    cout<<"Enter 1st Floating Integer:";
    cin>>f1;
    cout<<"Enter 2nd Floating Integer:";
    cin>>f2;
    cout<<"Largest Integer between "<<n1<<" and "<<n2<<" = "<<compare(n1,n2)<<endl;
    cout<<"Largest Floating Number between "<<f1<<" and "<<f2<<" = "<<compare(f1,f2);
    return 0;
}