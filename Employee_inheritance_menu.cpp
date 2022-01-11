#include <iostream>
#include <string>

using namespace std;

//Abstract Class Employee
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
    
    int get_id(){
        return id;
    }
    
    // Pure Virtual Function
    string virtual instanceOf() = 0;
    
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
    
    string instanceOf() override{
        return "Manager";
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
    Scientist(){};
    
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
    
    string instanceOf() override{
        return "Scientist";
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
    
    string instanceOf() override{
        return "Labourer";
    }
    
    ~Labourer(){
        delete family_size;
    }
};

int main(){
    int choice;
    int temp;
    string tem;
    int last = 0;
    
    Employee* list[10];
    
    while(true){
        cout << "\n--------Employee Management--------" << endl;
        cout << "1.Add Employee\n2.Show all Employee\n3.Search An employee\n4.Show Employee of one type\n5.Clear Screen\n6.Exit" << endl;
        cout << "your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout <<"Select type 1.Manager\t2.Scientist\t3.Labourer: ";
                cin >> temp;
                if(temp ==1){
                    list[last] = new Manager;
                }else if(temp == 2){
                    list[last] = new Scientist;
                }else{
                    list[last] = new Labourer;
                }
                list[last]->set_data();
                last++;
                break;
                
            case 2:
                for(int i=0;i<last;++i){
                    list[i]->display_data();
                }
                break;
                
            case 4:
                cout <<"Select type 1.Manager\t2.Scientist\t3.Labourer: ";
                cin >> temp;
                
                if(temp == 1) tem = "Manager";
                else if(temp == 2) tem = "Scientist";
                else tem = "Labourer";
                
                for(int i=0;i<last;++i){
                    if(list[i]->instanceOf() == tem)
                        list[i]->display_data();
                }
                break;
                
                
            case 3:
                cout << "Enter Employee id: ";
                cin >> temp;
                for(int i=0;i<last;++i){
                    if(list[i]->get_id() == temp)
                        list[i]->display_data();
                }
                break;
                
            case 5:
                system("cls");
                break;
                
            case 6:
                exit(0);
                
            default:
                cout << "Invalid Choice" << endl;
        }
    }
    
    return 0;
}