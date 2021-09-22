#include <iostream>
#include <string>

using namespace std;

class Books{
    string title;
    string author;
    float price;
    string publisher;
    int stock;
    
    static int successfull_transaction;
    static int unsuccessfull_transaction;
    
public:
    
    friend void issue_book(Books booklist[5],string tyt,string auth); // Friend function
    
    Books(){} // No args constructor
    
    Books(string tyt,string auth,float pr,string pub,int stk){ // Parameterized constructor
        title = tyt;
        author = auth;
        price = pr;
        publisher = pub;
        stock = stk;
    }
    
    void print_details(){
        cout<<"\nTitle : " << title << "\nAuthor : " << author << "\nPublisher : " << publisher << "\nPrice : " << price << "\nStock : " << stock << "\n" << endl; 
    }
    
    void print_details_in_row(){
        cout<< title << "\t\t" << author << "\t\t" << publisher << "\t\t\t" << price  << "\t\t" << stock << endl;
    }
    
    string get_author(){
        return author;
    }
    
    string get_title(){
        return title;
    }
    
    static void get_transaction_history(){
        cout << "\nSuccessfull Transactions : " << successfull_transaction << endl;
        cout << "\nUnsuccessfull Transactions : " << unsuccessfull_transaction <<endl;
    }
    
    void update_price(float pr){
        price = pr;
        cout << "The price of " << title << " was changed to " << price << endl;
    }
    
    void get_Price(int copies){
        if(copies > stock){
            cout << "Required Copies not in stock." << endl;
            unsuccessfull_transaction++;  // The transaction failed
        }else{
            cout << "Total cost : " << copies * price << endl;
            stock -= copies;
            successfull_transaction++;  // Transaction Success
        }
    }
    
    ~Books(){}
    
};

int Books::successfull_transaction = 0;
int Books::unsuccessfull_transaction = 0;

void issue_book(Books booklist[],string tyt,string auth){
    int copies;
    for(int i=0;i<5;++i){
        if(booklist[i].title == tyt && booklist[i].author == auth){
            booklist[i].print_details();
            cout << "Enter the number of copies required : ";
            cin >> copies;
            booklist[i].get_Price(copies);
            return;
        }
    }
    cout << "Required Book is not in the inventory." << endl;
}

int main(){
    Books booklist[5];
    int choice,stk;
    
    string tyt,auth,pub;
    float pr;
    
    while(1){
        cout << "\n--------------Jamia Book Store--------------\n\n";
        cout << "1.Set Inventory\n2.Issue Book\n3.Show inventory\n4.Get author's collection\n5.Search by title\n";
        cout << "6.Update Price\n7.Get transaction history\n8.Clear Screen\n9.Exit" << endl;
        cout << "\nSelect an option : ";
        cin >> choice;
        
        switch(choice){
            
            case 1 : 
                for(int i=0 ; i < 5 ; ++i){
                    cout << "\n---Book "<<i+1<<"----\n";
                    cout << "Enter title : ";
                    cin.sync();
                    getline(cin,tyt);
                    cout << "Enter author name : ";
                    getline(cin,auth);
                    cout << "Enter publisher : ";
                    getline(cin,pub);
                    cout << "Enter price : ";
                    cin >> pr;
                    cout << "Enter stock : ";
                    cin >> stk;
                    booklist[i] = Books(tyt,auth,pr,pub,stk); // Constructor
                }
                break;
            
            case 2 :
                cout << "Enter the title of book : ";
                cin.sync();
                getline(cin,tyt);
                cout << "Enter the author of book : ";
                getline(cin,auth);
                issue_book(booklist,tyt,auth); // Passing array of object as parameter(pointer to object[0])
                break;
                
            case 3 :
                cout<<"Title\t\t\tAuthor\t\t\tPublisher\t\tPrice\t\tStock\n";
                for(int i=0;i<5;++i) booklist[i].print_details_in_row();
                break;
                
            case 4 :
                cout << "Enter the name of author : ";
                cin.sync();
                getline(cin,auth);
                for(int i=0;i<5;++i) 
                    if(auth == booklist[i].get_author()) booklist[i].print_details();
                break;
                
            case 5 : 
                cout << "Enter the title : ";
                cin.sync();
                getline(cin,tyt);
                for(int i=0;i<5;++i) 
                    if(tyt == booklist[i].get_title()) booklist[i].print_details();
                break;
                
            case 6 : 
                cout << "Enter title : ";
                cin.sync();
                getline(cin,tyt);
                cout << "Enter price : ";
                cin >> pr;
                for(int i=0;i<5;++i) 
                    if(tyt == booklist[i].get_title()) booklist[i].update_price(pr);
                break;
            
            case 7 :
                Books::get_transaction_history();
                break;
            
            case 8 :
                system("cls");
                break;
            
            case 9 :
                exit(0);
                
            default : 
                cout << "Invalid Choice" << endl;
        }
        
    }
}