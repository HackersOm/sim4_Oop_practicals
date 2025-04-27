#include <iostream>
using namespace std;

// int main()
// {
//     int a=10,b=0;
//     cout<<a/b<<endl;
//     return 0;
// }

int main()
{
    int num1,num2,res;
    cout<<"Enter 1st Integer:";
    cin>>num1;
    cout<<"Enter 2nd Integer:";
    cin>>num2;
    try
    {
        if(num2==0)
        {
            throw num2;
        }
        else if (num1<0)
        {
            throw num1;
        }
        else
        {
            res=num1/num2;
            cout<<"Division="<<res;
        }
    }
    catch (int ex)
    {
        cout<<"Can't Divide by 0."<<endl;
    }
    catch (int ex1)
    {
        cout<<"Can't Divide with negative."<<endl;
    }
    return 0;
}