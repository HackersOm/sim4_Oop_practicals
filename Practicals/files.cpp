#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ofstream file;
    file.open("hello.txt");
    file.write("hello",5);
    file.write("Hello there",21);
    cout<<file.tellp()<<endl;
    file.close();
    ifstream file1;
    file1.open("hello.txt");
    string line;
    file1.seekg(0,ios::beg);
    cout<<file1.tellg()<<endl;
    while(getline(file1,line))
    {
        cout<<line<<endl;
    }
    return 0;
}