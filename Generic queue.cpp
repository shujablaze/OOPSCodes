#include <iostream>

using namespace std;

// Template Class
template <typename T>
class Queue {
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
    Node *back;
    
public:
    // No args constructor
    Queue(){
        top = nullptr;
    }
    
    void Enqueue(T data){
        if(top==nullptr){
            top = new Node(data,nullptr);
            return;
        }
        Node *temp = top;
        Node *newNode = new Node(data,nullptr);
        
        while(temp->next != nullptr){
            temp = temp->next;
        }
        
        // Adding to the back of the queue
        temp->next = newNode;
        back = newNode;
    }
    
    void dequeue(){
        if(top == nullptr){
            cout << "Queue empty " << endl;
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
        cout << popped << " was dequeued";
    }
    
    void peek(){
        if(top != nullptr) {
            cout << top->data << " is at the front";
            return;
        }
        
        cout << "Queue empty " << endl;
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
    ~Queue(){
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
    Queue<int>* stk = new Queue<int>;
    Queue<string>* stk_s = new Queue<string>;
    Queue<float>* stk_f = new Queue<float>;
    
    // Helper variable
    int temp_i;
    string temp_s;
    float temp_f;
    
    bool stack_present = true;
    
    int queue_type;
    
    cout << "Select Queue: 1.Integer Queue\t2.Float Queue\t3.String Queue\n";
    cin >> queue_type;
    
    
    while(true){
        cout << "\n----Queue Panel----\n" << endl;
        cout << "1.Create Queue\n2.Enqueue\n3.Dequeue\n4.Peek\n5.Delete Queue\n6.IsEmpty\n7.Display\n8.Clear Screen\n9.Change Queue\n10.exit" << endl;
        cout << "Enter Choice : ";
        cin >> choice;
        
        if(choice != 1 && !stack_present){
                cout << "Please Create a new queue to continue" << endl;
                continue;
        }
        
        switch(choice){
            case 1:
                if(queue_type==1){
                    stk = new Queue<int>();
                    cout << "New Integer queue Created" << endl;
                }
                else if(queue_type==2){
                    stk_f = new Queue<float>();
                    cout << "New Float queue Created" << endl;
                }
                else {
                    stk_s = new Queue<string>;
                    cout << "New String queue Created" << endl;
                }
                
                stack_present = true;
                break;
            
            case 2:
                cout << "Enter the data to enqueue : ";
                if(queue_type==1){
                    cin >> temp_i;
                    stk->Enqueue(temp_i);
                }
                else if(queue_type==2){
                    cin >> temp_f;
                    stk_f->Enqueue(temp_f);
                }
                else{
                    cin.sync();
                    getline(cin,temp_s);
                    stk_s->Enqueue(temp_s);
                }
                break;
                
            case 3:
                if(queue_type==1)stk->dequeue();
                else if(queue_type==2) stk_f->dequeue();
                else stk_s->dequeue();
                break;
                
            case 4:
                if(queue_type==1) stk->peek();
                else if(queue_type==2)stk_f->peek();
                else stk_s->peek();
                break;
            
                
            case 5:
                if(queue_type==1)delete stk;
                else if(queue_type==2)delete stk_f;
                else delete stk_s;
                
                cout << "queue has been deleted" << endl;
                
                stack_present = false;
                break;
                
            case 6:
                bool is_empty;
                
                if(queue_type==1)is_empty = stk->empty();
                else if(queue_type==2)is_empty = stk_f->empty();
                else is_empty = stk_s->empty();
                
                if(is_empty){
                    cout << "queue is empty" << endl;
                }
                else{
                    cout << "queue is not empty" << endl;
                }
                break;
                
            case 7:
                cout << "\n queue = ";
                if(queue_type==1)stk->display();
                else if(queue_type==2) stk_f->display();
                else  stk_s->display();
                
                break;
                
            case 8:
                system("cls");
                break;
                
            case 9:
                cout << "Select queue: 1.Integer queue\t2.Float queue\t3.String queue\n";
                cin >> queue_type;
                break;
                
            case 10:
                exit(0);
                break;
                
            default:
                cout << "Invalid Choice" << endl;
                
        }
    }
}