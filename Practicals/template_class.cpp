#include <iostream>

using namespace std;

template <class Stack_Item>
class Stack
{
    Stack_Item arr[30];
    int top=-1;
    public:
        void push(Stack_Item element)
        {
            arr[++top]=element;
            cout<<element<<" Pushed onto stack."<<endl;
        }
        void pop()
        {
            Stack_Item ele=arr[top];
            cout<<"Element "<<ele<<" poped out of stack."<<endl;
        }

        void display_stack()
        {
            cout<<"Elements in stack:"<<endl;
            for(int i=0;i<=top;i++)
            {
                cout<<arr[i]<<endl;
            }
        }
        
};

int main()
{
    Stack <int>int_stack;
    int_stack.push(20);
    int_stack.push(40);
    int_stack.push(50);
    int_stack.display_stack();
    int_stack.pop();

    Stack <string>string_stack;
    string_stack.push("Hello");
    string_stack.push("World");
    string_stack.push("Welcome");
    string_stack.push("C++");
    string_stack.display_stack();
    string_stack.pop();

    return 0;
}