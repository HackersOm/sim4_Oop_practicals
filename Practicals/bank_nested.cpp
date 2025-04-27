#include <iostream>
using namespace std;

class Bank
{
    private:
        int acc_no;
        long balance;
    public:

    Bank()
    {
        this->acc_no=0;
        this->balance=0;
    }
    Bank(int accNo,long bal)
    {
        this->acc_no=accNo;
        this->balance=bal;
    }

    void getInfo()
    {
        cout<<"Account No:"<<acc_no<<endl;
        cout<<"Current Balance:"<<balance<<endl;
    }

    class Transactions
    {
        public:
        void withdraw(Bank& obj,long amount)
        {
            if(amount<=obj.balance)
            {
                cout<<amount<<" Rs "<<"Successfully Witdrawed."<<endl;
                obj.balance=obj.balance-amount;
                return;
            }
            cout<<"Insufficient Amount."<<endl;
            cout<<"Current Balance="<<obj.balance<<endl;
        }

        void deposit(Bank& obj,long amount)
        {
            if(amount>0)
            {
                cout<<amount<<" Rs "<<"Deposited Amount successfully."<<endl;
                obj.balance=obj.balance+amount;
                return;
            }
            cout<<"Enter Valid amount."<<endl;
        }
    };
};
int main()
{
    Bank bank(13213,20000);
    bank.getInfo();
    Bank::Transactions trans;
    trans.withdraw(bank,10000);
    bank.getInfo();
    trans.deposit(bank,100000);
    bank.getInfo();

    Bank bank1(1324,12000);
    bank1.getInfo();
    return 0;
}