#include <iostream>
#include <string>

using namespace std;

class Employee{
private:
    long employee_num;
    string name;
    int salary;

public:
    void getData();
    void putData();
};

void Employee::getData(){
        cout << "Enter employee number: ";
        cin >> employee_num;
        cout << "Enter employee name: ";
        cin.sync();              // To Avoid getline reading newline char
        getline(cin,name) ;
        cout << "Enter employee salary: ";
        cin >> salary;
    }
    
void Employee::putData(){
    cout << employee_num << "\t\t\t" << name << "\t\t" << salary << endl;
    }

int main(){
    short n;
    Employee employees[10];
    
    cout << "Enter the number of employees (MAX 10) : ";
    cin >> n;
    
    for(short i=0;i<n;++i){
        cout << "\nEnter the details of employee " << i+1 << endl;
        employees[i].getData();
    }
    
    cout << "\nEMPLOYEE DETAILS\n" << endl;
    cout << "Employee Number\t\tName\t\t\tSalary" << endl;
    
    for(short i=0;i<n;++i) employees[i].putData();
    
    return 0;
}