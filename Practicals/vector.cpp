#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // creating empty vector
    // vector <int>v;
    
    // creating vector with 5 size
    // vector <int>V1(5);
    // for(int i=0;i<V1.size();i++)
    // {
    //     cout<<V1[i];
    // }
    // // creating vector with 5 size and all with 9 elements
    // vector <int>init_V(5,9);
    // cout<<endl;
    // for(int i=0;i<init_V.size();i++)
    // {
    //     cout<<init_V[i];
    // }

    // vector methods int type
    vector<int> v(6);
    // inserting in vector
    v.push_back(40);
    v.push_back(56);
    v.push_back(75);
    v.push_back(93);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    } 
    v.insert(v.begin()+4,100);
    v.insert(v.end()-2,200);
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    } 
    // updating element
    cout<<"\nBefore Updating "<<v[7]<<endl;
    v[7]=1000;
    cout<<"After updating "<<v[7]<<endl;
    //deleting element
    v.pop_back();
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    } 
    v.clear();
    cout<<endl;
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<"\t";
    }
    cout<<"\nSize of Vector:"<<v.size()<<endl;
    cout<<"Capacity of Vector:"<<v.capacity()<<endl;
    return 0;
}