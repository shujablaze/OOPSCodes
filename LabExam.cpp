#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    int emp_id;
    string name;
    
public:
    static int total_employees; // Static Variable 
    // Args constructor
    Employee(){
        emp_id = -1;
        name = "";
        total_employees++;
    }
    
    // Args constructor
    Employee(int emp_id,string name){
        this->name = name;
        this->emp_id = emp_id;
        total_employees++;
    }
    
    //Pure virtual function
    int virtual get_employee_type()=0;
    
    void virtual set_data(){
        cout << "Enter ID: ";
        cin >> emp_id;
        cout << "Enter name: ";
        cin.sync();
        getline(cin,name);
    }
    
    void virtual get_data(){
        cout << "Employee Id : " << emp_id << endl;
        cout << "Employee Name: " << name << endl;
    }
    
    int get_id(){
        return emp_id;
    }
    
    virtual ~Employee (){
        cout << "Employee Removed" << endl;
        total_employees--;
    }
    
};

class Teacher : public Employee{
protected:
    string highest_qualification;
    string subjects;
    
public:
    Teacher(){
        highest_qualification = "";
        subjects = "";
    }
    
    // Passing values to parent class constructor
    Teacher(int emp_id,string name,string hq,string subs)
        : Employee(emp_id,name){
        highest_qualification = hq;
        subjects = subs;
    }
    
    void set_data() override{
        Employee::set_data();
        cout << "Enter highest qualification: ";
        cin.sync();
        getline(cin,highest_qualification);
        cout << "Enter subject taught: ";
        cin.sync();
        getline(cin,subjects);
    }
    
    void get_data() override{
        Employee::get_data();
        cout << "Highest Qualification: " << highest_qualification << endl;
        cout << "Subjects taken: " << subjects << endl;
        
    }
    
    virtual ~Teacher(){
        cout << "Teacher Removed" << endl;
    }
};

class HOD : public Teacher{
    string department;
    int publications;
    
public:
    HOD(){
        department = "";
        publications = -1;
    }
    
    // Delegating to base class constructor
    HOD(int emp_id,string name,string hq,string sub,string department,int ten)
        :Teacher(emp_id,name,hq,sub){
        this->department = department;
        this->publications = ten;
    }

    void set_data() override{
        cout << "\n----HOD Input----" << endl;
        Teacher::set_data();
        cout << "Enter department: ";
        cin.sync();
        getline(cin,department);
        cout << "Enter no. of publication: ";
        cin >> publications;
    }
    
    void get_data() override{
        cout << "\n----HOD Details----" << endl;
        Teacher::get_data();
        cout << "Department: " << department << endl;
        cout << "Publications: " << publications << endl;
    }
    
    int get_employee_type() override{
        return 1;
    }
    
    virtual ~HOD(){
        cout << "HOD removed" << endl;
    }
};

class Proctor : public Teacher{
    int start_tenure;
    int end_tenure;
    
public:
    Proctor(){
        start_tenure = -1;
        end_tenure = -1;
    }
    
    Proctor(int emp_id,string name,string hq,string sub,string department,int sten,int eten)
        :Teacher(emp_id,name,hq,sub){
        this->start_tenure = sten;
        this->end_tenure = eten;
    }
    
    void set_data() override{
        cout << "\n ---Proctor Input---" << endl;
        Teacher::set_data();
        cout << "Enter year start of tenure: ";
        cin >> start_tenure;
        cout << "Enter year tenure ends: ";
        cin >> end_tenure;
    }
    
    void get_data() override{
        cout << "\n ---Proctor Details---" << endl;
        Teacher::get_data();
        cout << "Start of tenure: " << start_tenure << endl;
        cout << "End of tenure: " << end_tenure << endl;
    }
    
    int get_employee_type() override{
        return 2;
    }
    
    virtual ~Proctor(){
        cout << "Proctor Removed" << endl;
    }
};

class Warden : public Teacher{
    string hostel;
    
public:
    Warden(){
        hostel = "";
    }
    
    Warden(int emp_id,string name,string hq,string sub,string hostel)
        :Teacher(emp_id,name,hq,sub){
        this->hostel = hostel;
    }
    
    void set_data() override{
        cout << "\n---Warden Input---" << endl;
        Teacher::set_data();
        cout << "Enter hostel supervised: ";
        cin.sync();
        getline(cin,hostel);
    }
    
    void get_data() override{
        cout << "\n---Warden Details---" << endl;
        Teacher::get_data();
        cout << "Hostel supervised: " << hostel << endl;
    }
    
    int get_employee_type() override{
        return 3;
    }
    
    virtual ~Warden(){
        cout << "Warden Removed" << endl;
    }
};

int Employee::total_employees=0;

int main(){
    int choice,temp;
    int last{0};
    
    // Base class polymorphism
    Employee* list[20];
    
    while(1){
        cout << "\n----Employee Menu----"<< endl;
        cout << "Total Employees: " << Employee::total_employees << endl;
        cout << "1.Add Employee\n2.Update Employee\n3.Search Employee\n4.Display all\n5.Delete Employee\n6.Clear Screen\n7.Exit" << endl;
        cout << "Your choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "\t1.HOD\t2.Proctor\t3.Warden\n\t Choice: ";
                cin >> temp;
                if(temp == 1){
                    list[last] = new HOD();
                }
                else if(temp == 2){
                    list[last] = new Proctor();
                }
                else{
                    list[last] = new Warden();
                }
                list[last]->set_data();
                last++;
                break;
                
            case 2:
                cout << "Enter Id of employee to update: ";
                cin >> temp;
                
                for(int i=0;i<last;++i){
                    if(list[i]->get_id()==temp){
                        list[i]->set_data();
                    }
                }
                cout << "Details updated" << endl;
                break;
                
            case 3:
                cout << "Enter Id of employee: ";
                cin >> temp;
                for(int i=0;i<last;++i){
                    if(list[i]->get_id()==temp){
                        list[i]->get_data();
                    }
                }
                break;
                
            case 4:
                cout << "----All Employees----" << endl;
                for(int i=0;i<last;++i){
                        list[i]->get_data();
                }
                break;
                
            case 5:
                cout << "Enter Id :";
                cin >> temp;
                for(int i=0;i<last;++i){
                    if(list[i]->get_id() == temp){
                        // Swapping pointer to employee fired with last pointer to maintain indexing
                        swap(list[i],list[last-1]);
                        delete list[last-1]; // deleting employee
                        last--;
                        break;
                    }
                }
                break;
            case 6:
                system("cls");
                break;
                
            case 7:
                exit(0);
                break;
                
            default:
                cout << "Invalid Choice" << endl;
        }
    }
}