#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    fstream fileobj;
    string output;
    fileobj.open("newtextfile.txt",ios::ate);
    cout<<"Write content in file:";
    getline(cin,output);
    fileobj<<output;
    fileobj.close();

    fileobj.open("newtextfile.txt",ios::in);
    string line;
    while(getline(fileobj,line))
    {
        cout<<line<<endl;
    }
    fileobj.close();
    return 0;
}