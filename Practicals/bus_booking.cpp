#include <iostream>
using namespace std;

class BookTicket
{
    public:
        static int avail_seats; 
        int requested_tickets;
        BookTicket(int no_of_tickets):requested_tickets(no_of_tickets){};
        void book()
        {
            try{
                if (avail_seats<requested_tickets)
                {
                    throw avail_seats;
                }
                avail_seats=avail_seats-requested_tickets;
                cout<<"Tickets are booked."<<endl;
                cout<<"Available Seates:"<<avail_seats<<endl;
            }
            catch(...)
            {
                cout<<"Can't book the tickets!!"<<"\n"<<"Available Seates="<<avail_seats<<endl;
            }
        }
};

int BookTicket::avail_seats=45;

int main()
{
    BookTicket b1(5);
    b1.book();
    BookTicket b2(10);
    b2.book();
    BookTicket b3(35);
    b3.book();
    return 0;
}