#include <iostream>
#include <string>

using namespace std;

class Employee{
    int* employee_id;
    float* salary;
    string* name;
    char* sex;
    int* year_of_joining;
    

public:
    static int total_employees; // Static Variable 
    friend void sort(Employee* employee_list[],char type);
    friend void average(Employee* employee_list[]);
    
    // Dynamic Constructor
    Employee(int id,float sal,string nm,char sx,int yr){
        employee_id = new int(id);
        salary = new float(sal);
        name = new string(nm);
        sex = new char(sx);
        year_of_joining = new int(yr);
        
        total_employees++;
    }
    
    void get_details(){
        cout << "\nId : " << *employee_id <<endl; 
        cout << "Name : " << *name << endl;
        cout << "Sex : " << *sex << endl;
        cout << "Salary : " << *salary << endl;
        cout << "Joined in : " << *year_of_joining << "\n" <<endl;
    }
    
    void get_details_tabular(){
        cout << *employee_id << "\t\t" << *name << "\t\t" << *salary << "\t\t" << *sex << "\t\t" << *year_of_joining << endl;
    }
    
    int get_id(){
        return *employee_id;
    }
    
    ~Employee(){
        // Decrementing total employees
        total_employees--;
        delete name;
        delete salary;
        delete employee_id;
        delete sex;
        delete year_of_joining;
    }
    
};

int Employee::total_employees = 0;

// Friend function to sort the list According to type
// i=Employee_id    n=Name  s=salary
void sort(Employee* employee_list[],char type){
    for(int i=0;i<Employee::total_employees;++i){
        for(int j=0;j<Employee::total_employees - i -1;++j){
            if(type == 'i'){
                if(*(employee_list[j]->employee_id) > (*employee_list[j+1]->employee_id)){
                    swap(employee_list[j],employee_list[j+1]);
                }
            }
            else if(type == 'n'){
                if(*(employee_list[j]->name) > *(employee_list[j+1]->name)){
                    swap(employee_list[j],employee_list[j+1]);
                }
            }
            else if(type == 's'){
                if(*(employee_list[j]->salary) > *(employee_list[j+1]->salary)){
                    swap(employee_list[j],employee_list[j+1]);
                }
            }
        }
    }
    cout << "List Sorted" << endl;
}

// Unique function to calculate average
void average(Employee* employee_list[]){
    float sum = 0;
    for(int i=0;i<Employee::total_employees;++i){
        sum += *(employee_list[i]->salary);
    }
    cout << "The average salary is " << sum / (float)Employee::total_employees <<endl;
}

int main(){
    // To take user input helper variables
    int num,yr,id,option;
    float sal;
    string name;
    char sx;
    // List of pointer to employee object with max limit 10
    Employee* employee_list[10];
     // Menu
    while(1){
        cout << "------------Employee Admin------------\n" << endl;
        cout << "1.Add Employees\n2.Sort by Id\n3.Sort by name\n4.Sort by salary\n5.Search by id\n6.Print all details\n7.Get average salary\n";
        cout << "8.Remove Employee\n9.Clear Screen\n10.Exit\n"<<endl;
        cout << "Select an option : " ;
        cin >> option;

        switch(option){
            case 1:
                cout << "Enter total number of employees : ";
                cin >> num;
                if(num>10){
                    cout << "Only 10 employee allowed resetting num to 10" << endl;
                    num = 10;
                }
                // taking user input
                for(int i=0;i<num;++i){
                    cout << "\nEmployee " << i+1 <<endl;
                    cout << "Enter employee id : ";
                    cin >> id;
                    cout << "Enter name : ";
                    cin.sync();
                    getline(cin,name);
                    cout << "Enter salary : ";
                    cin >> sal;
                    cout << "Enter sex (M/F): ";
                    cin >> sx;
                    cout << "Enter year of joining : ";
                    cin >> yr;
                    employee_list[i] = new Employee(id,sal,name,sx,yr);
                }
                break;
            
            case 2:
                sort(employee_list,'i');
                break;
                
            case 3:
                sort(employee_list,'n');
                break;
                
            case 4:
                sort(employee_list,'s');
                break;
                
            case 5:
                cout << "Enter employee id : ";
                cin >> id;
                for(int i=0;i<Employee::total_employees;++i){
                    if(employee_list[i]->get_id() == id) employee_list[i]->get_details();
                }
                break;
                
            case 6:
                if(Employee::total_employees == 0){
                    cout << "No Employees" << endl;
                    break;
                }
                cout << "Id\t\tName\t\tSalary\t\tSex\t\tJoined In" <<endl;
                for(int i=0;i<Employee::total_employees;++i) employee_list[i]->get_details_tabular();
                break;
                
            case 7:
                average(employee_list);
                break;
                
            case 8:
                cout << "Enter Id :";
                cin >> id;
                for(int i=0;i<Employee::total_employees;++i){
                    if(employee_list[i]->get_id() == id){
                        // Swapping pointer to employee fired with last pointer to maintain indexing
                        swap(employee_list[i],employee_list[Employee::total_employees-1]);
                        delete employee_list[Employee::total_employees-1]; // deleting employee
                        cout << "Employee with id "<<id << " was fired." <<endl;
                        break;
                    }
                }
                break;
                
            case 9:
                system("cls");
                break;
                
            case 10:
                exit(0);
                break;
                
            default :
                cout <<"Invalid choice" <<endl;
        }
 
    }
    
}