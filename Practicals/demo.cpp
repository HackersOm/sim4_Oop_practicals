#include <iostream>
using namespace std;

class demo{
    private:
        int *p;
    public:
        void getInfo()
        {
            cout<<"Memory add="<<this->p<<"\t"<<"Value at add="<<*p<<endl;
        }
        void setInfo(int v)
        {
            *this->p=v;
        }
        demo(int x)
        {
            p=new int(x);
        }
        demo(const demo &obj)
        {
            // p=obj.p;
            p=new int(*(obj.p)); //deep constructor
        }

        ~demo()
        {
            delete p;
            cout<<"Destructor is called."<<endl;
        }
};

int main()
{
    demo d1(111);
    d1.getInfo();
    demo d2(d1);
    d2.getInfo();
    d2.setInfo(222);
    d2.getInfo();
    d2.~demo();
    d1.getInfo();
    return 0;
}