#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    int id;
    string name;
    float salary;
    string* sex;

protected:
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
    
    //Virtual Destructor
    virtual ~Employee (){
        delete sex;
    }
};

class Manager : public Employee{
    string title;
    string department;
    float* rating;
    
public:
    //No args constructor
    Manager(){
        title = "";
        department = "";
        rating = nullptr;
    };
    
    //Parameterized Constructor with delegation to parameterized base class constructor
    Manager(int id,string name,float salary,string sex,string title,string department,float rating)
        :Employee(id,name,salary,sex){
            this->title = title;
            this->department = department;
            this->rating = new float(rating); // Allocating dynamic memory
        }
    
    // Virtual function for user input
    void set_data() override{
        // Calling base class functionn to set Base class part
        cout << "\n----Manager----" << endl;
        Employee::set_data();
        
        float temp;
        
        cout << "Enter title: ";
        cin.sync();
        getline(cin,title);
        
        cout << "Enter department: ";
        cin >> department;
        
        cout << "Enter recent ratings: ";
        cin >> temp;
        
        this->rating = new float(temp);
    }
    
    void display_data() override{
        cout << "\n----Manager----" << endl;
        Employee::display_data();
        cout << "Title : " << title << endl;
        cout << "Department : " << department << endl;
        cout << "Rating : " << *rating << endl;
    }
    
    ~Manager(){
        delete rating;
    }
};

class Scientist : public Employee{
    int publications;
    char rank;
    string* field;
    
public:
    Scientist(){
        publications = 0;
        rank = '0';
        field = nullptr;
    };
    
    //Parameterized Constructor with delegation to parameterized base class constructor
    Scientist(int id,string name,float salary,string sex,int pubs,char rank,string field)
        ///:Employee(id,name,salary,sex){
           { publications = pubs;
            this->rank = rank;
            this->field = new string(field); // Allocating dynamic memory
        }
    
    void set_data() override{
        cout << "\n----Scientist----" << endl;
        // Calling base class functionn to set Base class part
        Employee::set_data();
        
        string temp;
        
        cout << "Enter number of publications: ";
        cin >> publications;
        cout << "Enter rank: ";
        cin>> rank;
        cout << "Field of research: ";
        cin.sync();
        getline(cin,temp);
        this->field = new string(temp); // Allocating dynamic memory
    }
        
    void display_data() override{
        cout << "\n----Scientist----" << endl;
        
        Employee::display_data();
        cout << "Publications : " << publications << endl;
        cout << "Rank : " << rank << endl;
        cout << "Field : "<< *field << endl;
    }
    
    ~Scientist(){
        delete field;
    }
};

class Labourer : public Employee{
    int overtime;
    string insurance;
    int* family_size;
    
public:
    Labourer(){
        overtime = 0;
        insurance = "";
        family_size = nullptr;
    };
    
    //Parameterized Constructor with delegation to parameterized base class constructor
    Labourer(int id,string name,float salary,string sex,int ot,string ins,int fs)
        :Employee(id,name,salary,sex){
            overtime = ot;
            insurance = ins;
            family_size = new int(fs); // Allocating dynamic memory
        }
        
    void set_data() override{
        cout << "\n----Labourer----" << endl;
        // Calling base class functionn to set Base class part
        Employee::set_data();
        
        int temp;
        
        cout << "Enter overtime: ";
        cin >> overtime;
        
        cout << "Is labourer insured(yes/no): ";
        cin >> insurance;
        
        cout << "No. of family members: ";
        cin >> temp;
        family_size = new int(temp); // Allocating dynamic memory
    }
    
    void display_data() override{
        cout << "\n----Labourer----" << endl;
        
        Employee::display_data();
        cout << "Overtime : " << overtime << " hrs" << endl;
        cout << "Family size: " << *family_size << " people" << endl;
        cout << "Insured : " << insurance << endl;
    }
    
    ~Labourer(){
        delete family_size;
    }
};

int main(){
    Manager m1,m2;
    Scientist s1,s2;
    Labourer l1,l2;
   
    m1.set_data();
    //m2->set_data();

    s1.set_data();
    //s2->set_data();

    l1.set_data();
    //l2->set_data();
   
    cout << "\n------Display------" << endl;

    m1.display_data();
    //m2->display_data();

    s1.display_data();
    //s2->display_data();

    l1.display_data();
    //l2->display_data();
    cout << endl;
    
    return 0;
}