#include <iostream>
#include <string>

using namespace std;

class Account{
    int account_num;
    string account_type;
    float balance;
    string holders_name;
    
    
public:
    friend void sort_accounts(Account arr[],int n);
    Account(){
        account_num=0;
        account_type="Inactive";
        balance = 0;
        holders_name="";
    }
    
    Account(int acc_num,string acc_type,float bal,string hold_name){
        account_num = acc_num;
        account_type = acc_type;
        balance = bal;
        holders_name = hold_name;
    }
    
    void deposit(int amount){
        balance += amount;
        cout << amount <<" deposited to account number "<<account_num<<endl;
    }
    
    void withdraw(int amount){
        if(balance - amount < 0){
            cout<<"Insufficient balance. "<<endl;
        }else{
            balance -= amount;
            cout << amount <<" withdrawn from account number "<<account_num<<endl;
        }
    }
    
    void display_basic(){
        cout << "This account belongs to " << holders_name << " with balance "<<balance<<endl;
    }
    
    void display_all(){
        cout << account_num << "\t\t\t" << holders_name << "\t\t" << account_type << "\t\t\t" << balance << endl; 
    }
    
    int get_accnum(){
        return account_num;
    }
};

void sort_accounts(Account arr[],int n){
    for(int i=0;i<n;++i){
        for(int j=0;j<n-i-1;++j)
            if(arr[j].balance > arr[j+1].balance){
                Account temp;
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
    }
}

int main(){
    Account accounts[10];
    int choice,acc_num,n,amt;
    float balance;
    string name,acc_type;
    
    cout<<"Enter the number of accounts: ";
    cin >> n;
    
    for(int i=0;i<n;++i){
        cout << "\nEnter holder's name : ";
        cin.sync();
        getline(cin,name);
        cout << "Enter balance : ";
        cin >> balance;
        cout << "Enter account type : ";
        cin >> acc_type;
        accounts[i] = Account(i+1,acc_type,balance,name);
    }

    while(1){
        cout << "\n------JAMIA BANK CONTROL PANEL-------\n"<<endl;
        cout<<"\n1. Print All Account details.\n2.Sort Accounts\n3.Get details of single Account\n4.Withdraw from an Account\n5.Deposit to an account\n";
        cout << "6.Clear Screen\n7.Exit\n";
        cout<<"Enter choice: ";
        cin >> choice;
        cout<<"\n";
        
        
        switch(choice){
            case 1 : cout<<"Account Number\t\tHolder's Name\t\tAccount type\t\tBalance"<<endl;
                    for(int i=0;i<n;++i) accounts[i].display_all();
                    break;
            
            case 2 : sort_accounts(accounts,n);
                    cout<<"Account sorted successfully."<<endl;
                    break;
            
            case 3 : cout<<"Enter account number : ";
                    cin >> acc_num;
                    for(int i=0;i<n;++i) if(accounts[i].get_accnum() == acc_num) accounts[i].display_basic();
                    break;
                    
            case 4 : cout<<"Enter account number : ";
                    cin >> acc_num;
                    cout<<"Enter Amount : ";
                    cin >> amt;
                    for(int i=0;i<n;++i) if(accounts[i].get_accnum() == acc_num) accounts[i].withdraw(amt);
                    break;
            case 5 : cout<<"Enter account number : ";
                    cin >> acc_num;
                    cout<<"Enter Amount : ";
                    cin >> amt;
                    for(int i=0;i<n;++i) if(accounts[i].get_accnum() == acc_num) accounts[i].deposit(amt);
                    break;
                    
            case 6 : system("cls");
                     break;
            
            case 7 : exit(0);
                     break;
            
            default : cout<<"Invalid Option\n";
        }

        
    }
}