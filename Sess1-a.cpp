#include <iostream>
#include <string>

using namespace std;

struct Employee{
    string name;
    int id;
    float salary;
};

struct Node{
    Employee e;
    Node * next;
};

class Linkedlist{
    Node *head;
    
public:
    friend void fireEmployee(int id,Linkedlist& list);
    friend void updateInfo(int id,Linkedlist& list);
    Linkedlist(){
        head = nullptr;
    }
    
    void addEmployee(Employee e){
        Node * temp = new Node;
        temp->e = e;
        temp->next = head;
        head = temp;
    }
    
    void display(){
        Node *index = head;
        
        cout << "\nLIST OF EMPLOYEE" <<endl;
        while(index!=nullptr){
            
            cout<<index->e.name << " | " << index->e.id << " | " << index->e.salary << endl;
            index = index->next;
        }
        cout << endl;
        
    }
};

void fireEmployee(int id,Linkedlist& list){
    Node *index = list.head;
    Node *prev = nullptr;
    
    // Checking if head is match
    if(index != nullptr && index->e.id == id){
        list.head = index->next; // deleted head
        delete index;
        return;
    }
    
    // Traversing Linkedlist
    while(index!=nullptr){
        if(index->e.id == id){
            // Deleted index which matched
            prev->next = index->next;
            index->next = nullptr;
            cout << "Employee with id " << id << " was fired" << endl;
            return;
        }
        
        prev = index;
        index = index->next;
    }
    // if no id match was found
    cout << "No such Employee exist " << endl;
}

void updateInfo(int id,Linkedlist& list){
    Node *index = list.head;
    string na;
    float sal;
    
    // Traversing Linkedlist
    while(index!=nullptr){
        if(index->e.id == id){
            // Enter new updated info for name
            cout << "Enter updated name (current = " << index->e.name <<") : ";
            cin.sync();
            getline(cin,na);
            index->e.name = na;
            // Enter new updated info for salary
            cout << "Enter updated salary (current = " << index->e.salary <<") : ";
            cin >> sal;
            index->e.salary = sal;
            return;
        }
        index = index->next;
    }
    
}

int main(){
    int choice;
    Linkedlist l1;
    
    // Helper variables
    int id;

    
    while(true){
        cout << "\nEmployee Management System" << endl;
        cout << "1.Add Employee\n2.Fire Employee\n3.Update Employee\n4.Display\n5.Exit" << endl;
        cin >> choice;
        
        switch(choice){
            case 1:
            // Gettting employee info
                for(int i=0;i<3;++i){
                    Employee temp;
                    cout << "\n Employee "<< i << endl;
                    cout << "Enter employee id: ";
                    cin >> temp.id;
                    cout << "Enter employee name: ";
                    cin.sync();
                    getline(cin,temp.name);
                    cout << "Enter employee salary: ";
                    cin >> temp.salary;
                    l1.addEmployee(temp);
                }
                break;
            
            case 2:
                cout << "Enter id of employee to be fired: ";
                cin >> id;
                fireEmployee(id,l1);
                break;
            
            case 3:
                cout << "Enter id of employee to be updated: ";
                cin >> id;
                updateInfo(id,l1);
                break;
                
            case 4:
                l1.display();
                break;
            
            case 5:
                exit(0);
                break;
                
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}
