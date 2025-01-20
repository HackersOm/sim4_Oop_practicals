#include<iostream>
#include<iomanip>
#include<fstream>
using namespace std;
#define MAX_AMOUNT 100000 
#define FILE_NAME "transcation.txt"


void depositeAmount(int amt,int* total,int * arr_tran,int * tr_count){

        
        
        if((total[*tr_count]+amt) >= MAX_AMOUNT) {
            cout<<"can't deposite, Amount greated than bank limit "<<endl;
            return;
        }
        cout<<"Amount deposited on account"<<endl;
        arr_tran[++(*tr_count)] = amt;

        if(*tr_count == 0)
            total[*tr_count] = amt;
        else
            total[*tr_count] = total[*tr_count-1]+ amt;
        ofstream file ;
        file.open(FILE_NAME,ios::app);
        setfill('0');
        setw(6);
        string str = " Transaction Deposited of Rupees :\t +"+to_string(arr_tran[*tr_count])+"\n";
        file<<str;
        file.close();
        return ;

}
void withdrawAmount(int amt,int* total,int arr_tran[],int* tr_count){

    if(*tr_count == -1 || amt>total[*tr_count]){
        cout<<"No  that much amount in account "<<endl;
        return ;
    }
    cout<<"Amount withdraw from account"<<endl;
    arr_tran[++(*tr_count)] =  amt;
    if(*tr_count == 0)
            total[*tr_count] = total[*tr_count] - amt;
        else
            total[*tr_count] = total[*tr_count-1]- amt;
    
    ofstream file ;
        file.open(FILE_NAME,ios::app);
        setfill('0');
        setw(6);
        string str = " Transaction withdraw of Rupees :\t -"+to_string(arr_tran[*tr_count])+"\n";
        file<<str;
        file.close();
    return ;
}
void print(int  arr_tran[], int tr_count,int* total){
    if(tr_count == -1){
            cout<<"No Any Transaction in this Account"<<endl;
            return ;
        }

    cout<<"Print the last 10 transcation "<<endl<<endl;

    if(tr_count >= 0 && tr_count < 10) {
        cout<<"Transaction Deposited of Rupees : \t +"<<setw(6)<<setfill('0')<<arr_tran[0]<<endl;
    }
    int i = (tr_count>10)? (tr_count - 10) : 1;
    cout<<"i value :-"<<i<<endl;
    while(i<=tr_count){
        
        if(total[i-1]>total[i]){
            cout<<" Transaction withdraw of Rupees :\t -"<<setw(6)<<setfill('0')<<(arr_tran[i])<<endl;
            i++;
            
        }
        else{
            cout<<" Transaction Deposited of Rupees :\t +"<<setw(6)<<setfill('0')<<(arr_tran[i])<<endl;
            i++;
        }
    }
    cout<<"---------------------------------------------------------"<<endl;
    cout<<"\t\t\t\tTotal: "<<total[tr_count]<<endl<<endl;
}

int main(){
     
     int total[1000],ch;
     int tr_count = -1;
     int  arr_tran[1000];
     int amt = 0;
     cout <<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n"
     <<" W E L C O M E   T O   O O P   B A N K \n"
     <<"*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*\n\n\n";
    do{
        cout<<"\n1)Deposite Amount \n2)Withdraw Amount \n3)print last 10 Transcation \n4)Exit\n\n\n";
        cin>>ch;
        switch(ch){
            case 1: cout<<"Enter Amount to Deposite : ";
                    cin>>amt;
                    cout<<endl;
                    depositeAmount(amt,total,arr_tran,&tr_count);
                    break;
            case 2:
                    cout<<"Enter Amount to withdraw : ";
                    cin>>amt;
                    cout<<endl;
                     withdrawAmount(amt,total,arr_tran,&tr_count);
                    break;
            case 3: print(arr_tran,tr_count,total);
                    break;
            case 4: break;
            default: cout<<"Worng Choice\n";
        }
    }while(ch != 4);


    return 0;
}