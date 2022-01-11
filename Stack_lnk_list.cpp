#include <iostream>

using namespace std;

class Stack{
    
    // Node inner class
    class Node{
    public:
        int data;
        Node *next;
        // No params constructor for node 
        Node(){
            data = 0;
            next = nullptr;
        }
        // Params constructor for node
        Node(int data,Node * next){
            this->data = data;
            this->next = next;
        }
    };
    
    Node *top;
    
public:
    // No args constructor
    Stack(){
        top = nullptr;
    }
    
    void push(int data){
        Node *temp = new Node(data,top);
        top = temp;
    }
    
    int pop(){
        if(top==nullptr){
            cout << "Stack empty" << endl;
            return -1;
        }
        
        // Storing popped item
        int popped = top->data;
        
        Node *temp = top;
        // Removing element at top
        top = top->next;
        
        // Freeing memory taken by prev top element
        temp->next = nullptr;
        delete temp;
        return popped;
    }
    
    int peek(){
        if(top != nullptr) return top->data;
        
        cout << "Stack empty" << endl;
        return -1;
    }
    
    bool empty(){
        return top == nullptr;
    }
    
    void display(){
        Node *temp = top;
        if(temp == nullptr){
            cout << "NuLL" <<endl;
            return;
        }
        while(temp->next != nullptr){
            cout << temp->data << " | ";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
    
    // Destructor
    ~Stack(){
        Node *next,*temp;
        next = top;
        
        // Deleting all nodes
        while(next!=nullptr){
            temp = next;
            next = next->next;
            
            delete temp;
        }
    }
};


int main(){
    Stack* stk = new Stack();
    
    int choice;
    // Helper variable
    int temp;
    bool stack_present = true;
    
    while(true){
        cout << "\n----Stack Panel----\n" << endl;
        cout << "1.Create Stack\n2.Push\n3.Pop\n4.Peek\n5.Delete Stack\n6.IsEmpty\n7.Display\n8.Clear Screen\n9.Exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        
        if(choice != 1 && !stack_present){
                cout << "Please Create a new stack to continue" << endl;
                continue;
        }
        
        switch(choice){
            case 1:
                stk = new Stack();
                cout << "New Stack Created" << endl;
                stack_present = true;
                break;
            
            case 2:
                cout << "Enter the number to push : ";
                cin >> temp;
                stk->push(temp);
                break;
                
            case 3:
                temp = stk->pop();
                if(temp!=-1) cout << temp << " was popped from stack." << endl;
                break;
                
            case 4:
                temp = stk->peek();
                if(temp!=-1) cout << temp << " is at the top of stack." << endl;
                break;
                
            case 5:
                delete stk;
                cout << "Stack has been deleted" << endl;
                stack_present = false;
                break;
                
            case 6:
                if(stk->empty()){
                    cout << "Stack is empty" << endl;
                }
                else{
                    cout << "Stack is not empty" << endl;
                }
                break;
                
            case 7:
                cout << "\n Stack = ";
                stk->display();
                break;
                
            case 8:
                system("cls");
                break;
                
            case 9:
                exit(0);
                break;
                
            default:
                cout << "Invalid Choice" << endl;
                
        }
    }
}