#include <iostream>
#include <string>

using namespace std;

class Employee{
protected:
    
    int emp_id;
    string name;
    int age;
    
public:
    //No args constructor
    Employee(){
        emp_id = 0;
        name = "";
        age = 0;
    }
    
    //Args Constructor
    Employee(int id,string nm,int a){
        emp_id = id;
        name = nm;
        age = a;
    }
    // Function to get user input
    void virtual set_info(){
        cout << "Enter employee id: ";
        cin >> emp_id;
        
        cout << "Enter employee name: ";
        cin.sync();
        getline(cin,name);
        
        cout << "Enter age: ";
        cin >> age;
    }
    
    void virtual get_info(){
        cout << "ID: " << emp_id << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
    
    int return_id(){
        return emp_id;
    }
    // Pure virtual functions
    void virtual get_payroll() = 0;
    
    int virtual employee_type()=0;
    
    ~Employee(){
        cout << "Destroying Employee" << endl;
    }
};

class Salaried_Employee:public Employee{
    float salary;
    
public:

    //No args constructor
    Salaried_Employee(){
        salary = 0;    
    }
    
    //Args constructor overloaded
    Salaried_Employee(int id,string name,int age,float sal)
        :Employee(id,name,age){
        salary = sal;    
    }
    
    void set_info() override{
        cout << "\nSalaried Employee" << endl;
        Employee::set_info();
        
        cout << "Enter Salary: ";
        cin >> salary;
    }
    
    void get_info() override{
        cout << "\nSalaried Employee" << endl;
        Employee::get_info();
        cout << "Salary: " << salary << endl;
    }
    
    void get_payroll() override{
        cout << "Salaried Employee " << name << " was paid " << salary << endl;
    }
    
    int employee_type() override{
        return 1;
    }
    
    ~Salaried_Employee(){
        cout << "Salaried Employee" << endl;
    }
};

class Hourly_Employee:public Employee{
    float hourly_salary;
    int hrs_worked;
    
public:
    
    Hourly_Employee(){
        hourly_salary = 0;
        hrs_worked = 0;
    }
//Args constructor overloaded
    Hourly_Employee(int id,string name,int age,float sal,int hrsw)
        :Employee(id,name,age){
        hourly_salary = sal;   
        hrs_worked = hrsw;
    }
    
    void set_info() override{
        cout << "\nHourly Employee" << endl;
        Employee::set_info();
        
        cout << "Enter Hourly Salary: ";
        cin >> hourly_salary;
        
        cout << "Enter number of hours worked: ";
        cin >> hrs_worked;
    }
    
    void get_info() override{
        cout << "\nHourly Employee" << endl;
        Employee::get_info();
        cout << "Hourly salary: " << hourly_salary << endl;
        cout << "Hour Worked: " << hrs_worked << endl;
    }
    
    void get_payroll() override{
        if(hrs_worked > 40){
            cout << "Hourly employee " << name << " was paid " << (hourly_salary * 40) + ((hrs_worked-40)*hourly_salary*1.5) << endl;
        }else{
            cout << "Hourly employee " << name << " was paid " << (hourly_salary * hrs_worked) << endl;
        }
    }
    
    int employee_type() override{
        return 2;
    }
    
    ~Hourly_Employee(){
        cout << "Destroying Hourly Employee" << endl;
    }
};

class Commission_Employee : public Employee{
protected:
    float total_sales;
    float commission;

public:    
    //No args constructor
    Commission_Employee(){
        total_sales = 0;
        commission = 0;
    }
    
    //Args constructor overloaded
    Commission_Employee(int id,string name,int age,float sale,float comm)
        :Employee(id,name,age){
        total_sales = sale;   
        commission = comm;
    }
    

     void set_info() override{
        cout << "\nCommission Employee" << endl;
        Employee::set_info();
        
        cout << "Enter total sales: ";
        cin >> total_sales;
        
        cout << "Enter commission rate: ";
        cin >> commission;
    }
    
    void get_info() override{
        cout << "\nCommision Employee" << endl;
        Employee::get_info();
        cout << "Total Sales: " << total_sales << endl;
        cout << "Commission: " << commission << endl;
    }
    
    void get_payroll() override{
        cout << "Commission Employee " << name << " was paid " << (total_sales / 100) * commission << endl;
    }
    
    int employee_type() override{
        return 3;
    }
    
    ~Commission_Employee(){
        cout << "Destroying Commission Employee" << endl;
    }
};

class Base_plus_Commission_Employee : public Commission_Employee{
    float base_pay;
    bool apply_bonus;

public:
    Base_plus_Commission_Employee(){
        base_pay = 0;
        apply_bonus = 0;
    }
    //Args constructor overloaded
    Base_plus_Commission_Employee(int id,string name,int age,float sale,float comm,float bp,bool bonus)
        :Commission_Employee(id,name,age,sale,comm){
        base_pay = bp;   
        apply_bonus = bonus;
    }

    void set_info() override{
        cout << "\nBasePlusCommission Employee" << endl;
        Employee::set_info();
        cout << "Enter total sales: ";
        cin >> total_sales;
        
        cout << "Enter commission rate: ";
        cin >> commission;
        
        cout << "Enter Base pay: " ;
        cin >> base_pay;
        
        cout << "Add 10% bonus(1 for yes / 0 for no): ";
        cin >> apply_bonus;
    }
    
    void get_info() override{
         cout << "\nBasePlusCommission Employee" << endl;
         Employee::get_info();
         cout << "Total Sales: " << total_sales << endl;
         cout << "Commission: " << commission << endl;
         cout << "Base Pay: " << base_pay << endl;
    }
    
    void get_payroll() override{
        if(apply_bonus){
            cout << "BasePlusCommission Employee " << name << " was paid " << ((total_sales / 100) * commission) + (base_pay) + (base_pay / 10)<< endl;
        }else{
            cout << "BasePlusCommission Employee " << name << " was paid " << (total_sales / 100) * commission + (base_pay)<< endl;
        }
    }
    
    int employee_type() override{
        return 4;
    }
    
    ~Base_plus_Commission_Employee(){
        cout << "Destroying Base plus commission Employee" << endl;
    }
};

int main(){
    int choice;
    int temp;
    int last = 0;
    
    Employee* list[20];
    
    while(true){
        cout << "\n--------Employee Manager--------" << endl;
        cout << "1.Add Employee\n2.Display Employees\n3.Find Employee\n4.Get Payroll\n5.Clear Screen\n6.Exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch(choice){
            case 1:
                cout << "1.Salaried\t2.Hourly\t3.Commission\t4.BasePlusCommission" << endl;
                cin >> temp;
                if(temp == 1) 
                    list[last] = new Salaried_Employee;
                else if(temp == 2) 
                    list[last] = new Hourly_Employee;
                else if(temp == 3) 
                    list[last] = new Commission_Employee;
                else 
                    list[last] = new Base_plus_Commission_Employee;
                
                list[last]->set_info();
                last++;
                break;
                
            case 2:
                cout << "1.Salaried\t2.Hourly\t3.Commission\t4.BasePlusCommission\t5.All" << endl;
                cin >> temp;
                if(temp==5)
                    for(int i = 0; i < last ; ++i){
                        list[i]->get_info();
                        list[i]->get_payroll();
                    }
                else
                    for(int i = 0; i < last ; ++i) 
                        if(list[i]->employee_type() == temp){
                            list[i]->get_info();
                            list[i]->get_payroll();
                        }
                break;
                
            case 3:
                cout << "Enter employee's Id: ";
                cin >> temp;
                for(int i = 0; i < last ; ++i) 
                    if(list[i]->return_id() == temp){
                        list[i]->get_info();
                        list[i]->get_payroll();
                    }
                break;
                
            case 4:
                cout << "\nAll Payrolls\n" << endl;
                for(int i = 0; i < last ; ++i) 
                    list[i]->get_payroll();
                cout << endl;
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
}