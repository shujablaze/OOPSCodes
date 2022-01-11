#include <iostream>

using namespace std;

// Template Class
template <typename T>
class Stack {
    // Node inner class
    class Node{
    public:
        T data;
        Node *next;
        // No params constructor for node 
        Node(){
            data = 0;
            next = nullptr;
        }
        // Params constructor for node
        Node(T data,Node * next){
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
    
    void push(T data){
        Node *temp = new Node(data,top);
        top = temp;
    }
    
    void pop(){
        if(top == nullptr){
            cout << "Stack empty " << endl;
            return;
        }
        
        // Storing popped item
        T popped = top->data;
        
        Node *temp = top;
        // Removing element at top
        top = top->next;
        
        // Freeing memory taken by prev top element
        temp->next = nullptr;
        delete temp;
        cout << popped << " was popped";
    }
    
    void peek(){
        if(top != nullptr) {
            cout << top->data << " is at the top";
            return;
        }
        
        cout << "Stack empty " << endl;
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
    int choice;
    // Stack objects with different types
    Stack<int>* stk = new Stack<int>;
    Stack<string>* stk_s = new Stack<string>;
    Stack<float>* stk_f = new Stack<float>;
    
    // Helper variable
    int temp_i;
    string temp_s;
    float temp_f;
    
    bool stack_present = true;
    
    int stack_type;
    
    cout << "Select stack: 1.Integer Stack\t2.Float Stack\t3.String Stack\n";
    cin >> stack_type;
    
    
    while(true){
        cout << "\n----Stack Panel----\n" << endl;
        cout << "1.Create Stack\n2.Push\n3.Pop\n4.Peek\n5.Delete Stack\n6.IsEmpty\n7.Display\n8.Clear Screen\n9.Change Stack\n10.exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        
        if(choice != 1 && !stack_present){
                cout << "Please Create a new stack to continue" << endl;
                continue;
        }
        
        switch(choice){
            case 1:
                if(stack_type==1){
                    stk = new Stack<int>();
                    cout << "New Integer Stack Created" << endl;
                }
                else if(stack_type==2){
                    stk_f = new Stack<float>();
                    cout << "New Float Stack Created" << endl;
                }
                else {
                    stk_s = new Stack<string>;
                    cout << "New String Stack Created" << endl;
                }
                
                stack_present = true;
                break;
            
            case 2:
                cout << "Enter the data to push : ";
                if(stack_type==1){
                    cin >> temp_i;
                    stk->push(temp_i);
                }
                else if(stack_type==2){
                    cin >> temp_f;
                    stk_f->push(temp_f);
                }
                else{
                    cin.sync();
                    getline(cin,temp_s);
                    stk_s->push(temp_s);
                }
                break;
                
            case 3:
                if(stack_type==1)stk->pop();
                else if(stack_type==2) stk_f->pop();
                else stk_s->pop();
                break;
                
            case 4:
                if(stack_type==1) stk->peek();
                else if(stack_type==2)stk_f->peek();
                else stk_s->peek();
                break;
            
                
            case 5:
                if(stack_type==1)delete stk;
                else if(stack_type==2)delete stk_f;
                else delete stk_s;
                
                cout << "Stack has been deleted" << endl;
                
                stack_present = false;
                break;
                
            case 6:
                bool is_empty;
                
                if(stack_type==1)is_empty = stk->empty();
                else if(stack_type==2)is_empty = stk_f->empty();
                else is_empty = stk_s->empty();
                
                if(is_empty){
                    cout << "Stack is empty" << endl;
                }
                else{
                    cout << "Stack is not empty" << endl;
                }
                break;
                
            case 7:
                cout << "\n Stack = ";
                if(stack_type==1)stk->display();
                else if(stack_type==2) stk_f->display();
                else  stk_s->display();
                
                break;
                
            case 8:
                system("cls");
                break;
                
            case 9:
                cout << "Select stack: 1.Integer Stack\t2.Float Stack\t3.String Stack\n";
                cin >> stack_type;
                break;
                
            case 10:
                exit(0);
                break;
                
            default:
                cout << "Invalid Choice" << endl;
                
        }
    }
}