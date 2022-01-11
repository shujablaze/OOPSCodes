#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    int id;
    string name;
    float salary;
    string* sex;

public:
    //No args constructor
    Employee(){
        id = 0;
        name = "";
        salary = 0;
        sex = nullptr;
    };
    
    //Parameterized Constructor
    Employee(int id,string name,float salary,string sex){
        this->id = id;
        this->name = name;
        this->salary = salary;
        this->sex = new string(sex); // Allocating dynamic memory
    }
    
    // Virtual function for user input
    void virtual set_data(){
        string sex;
        
        cout << "Enter Id: ";
        cin >> id;
        cout << "Enter name: ";
        cin.sync();
        getline(cin,name);
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter sex(male/female): ";
        cin >> sex;
        this->sex = new string(sex); // Allocating dynamic memory
    }
    
    void virtual display_data(){
        cout << "Id : "<< id << endl;
        cout << "Name : "<< name << endl;
        cout << "Salary : "<< salary << endl;
        cout << "Sex: " << *sex << endl;
    }
    
    void virtual speak()=0;
    
    //Virtual Destructor
    virtual ~Employee (){
        delete sex;
    }
};

class Assisstant : public Employee{
    string department;
    float* rating;
    
public:
    //No args constructor
    Assisstant(){
        department = "";
        rating = nullptr;
    };
    
    //Parameterized Constructor with delegation to parameterized base class constructor
    Assisstant(int id,string name,float salary,string sex,string department,float rating)
        :Employee(id,name,salary,sex){
            this->department = department;
            this->rating = new float(rating); // Allocating dynamic memory
        }
    
    // Virtual function for user input
    void set_data() override{
        // Calling base class functionn to set Base class part
        cout << "\n----Assisstant----" << endl;
        Employee::set_data();
        
        float temp;
        
        
        cout << "Enter department: ";
        cin >> department;
        
        cout << "Enter recent ratings: ";
        cin >> temp;
        
        this->rating = new float(temp);
    }
    
    void display_data() override{
        cout << "\n----Assisstant----" << endl;
        Employee::display_data();
        cout << "Department : " << department << endl;
        cout << "Rating : " << *rating << endl;
    }
    
    void speak() override{
        cout << "\n\nAssisstant---I Am the Assisstant in dept" <<department<< endl;
    }
    
    ~Assisstant(){
        delete rating;
    }
};

class Professor : public Employee{
    int publications;
    string* field;
    
public:
    Professor(){
        publications = 0;
        field = nullptr;
    };
    
    //Parameterized Constructor with delegation to parameterized base class constructor
    Professor(int id,string name,float salary,string sex,int pubs,string field)
        :Employee(id,name,salary,sex){
            publications = pubs;
            this->field = new string(field); // Allocating dynamic memory
        }
    
    void set_data() override{
        cout << "\n----Professor----" << endl;
        // Calling base class functionn to set Base class part
        Employee::set_data();
        
        string temp;
        
        cout << "Enter number of publications: ";
        cin >> publications;

        cout << "Field of research: ";
        cin.sync();
        getline(cin,temp);
        this->field = new string(temp); // Allocating dynamic memory
    }
        
    void display_data() override{
        cout << "\n----Professor----" << endl;
        
        Employee::display_data();
        cout << "Publications : " << publications << endl;
        cout << "Field : "<< *field << endl;
    }
    
    void speak() override{
        cout << "\nProfessor--I am the professor my name is " << name << endl;
    }
    
    ~Professor(){
        delete field;
    }
};

int main(){
    Employee* e1 = new Professor();
    Employee* e2 = new Assisstant();
    
    e1->set_data();
    e2->set_data();
    //Speaking
    e1->speak();
    e1->display_data();
    //Speaking 
    e2->speak();
    e2->display_data();
}