#include <iostream>
#include <string>

using namespace std;

class Vehicle{
protected:
    string model;
    string company;
    float cost;
    
public:
    Vehicle(){
        cout << "Base Vehicle No args constructor executed" << endl;
        model = "";
        company = "";
        cost = -1;
    }
    
    Vehicle(string model, string company, float cost){
        cout << "Base Vehicle args constructor executed" << endl;
        this->model = model;
        this->company = company;
        this->cost = cost;
    }
    
    virtual void get_details(){
        cout << "Enter Company Name: ";
        cin.sync();
        getline(cin,company);
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter cost($): ";
        cin >> cost;
    }
    
    virtual void print_details(){
        cout << "Company : " << company << endl;
        cout << "Model : "<< model << endl;
        cout << "Cost : "<< cost << endl; 
        
    }
    
    virtual ~Vehicle(){
        cout << "Destructor Called" << endl;
    }
};

class Electric_car : public Vehicle{
    float battery_range;
    int chargin_time;
    
public:
    Electric_car(){
        cout << "Electric car No args constructor executed" << endl;
        battery_range = 0.0f;
        chargin_time = -1;
    }
    
    Electric_car(string company,string model,float cost,float bt,int cht)
        :Vehicle(model,company,cost){
        cout << "Electric car args constructor executed" << endl;
        battery_range = bt;
        chargin_time = cht;
    }
    
    void get_details () override{
        cout << "\nElectric Car" << endl;
        Vehicle::get_details();
        cout << "Enter battery range: ";
        cin >> battery_range;
        cout << "Enter charging time: ";
        cin >> chargin_time;
    }
    
    void print_details() override{
        cout << "\nElectric Car Details" << endl;
        Vehicle::print_details();
        cout << "Charging time(hrs): " << chargin_time << endl;
        cout << "Battery range: " << battery_range << endl;
    }
    
    ~Electric_car(){
        cout << "Electric car destructor call" << endl;
    }
};

class Helicopter : public Vehicle{
    int number_of_blades;
    float lifting_capacity;
    
public:
    Helicopter(){
        cout << "Helicopter No args constructor executed" << endl;
        number_of_blades = 0;
        lifting_capacity = 0.0f;
    }
    
    Helicopter(string company,string model,float cost,float lc,int nb)
        :Vehicle(model,company,cost){
        number_of_blades = nb;
        lifting_capacity = lc;
    }
    
    void get_details () override{
        cout << "\nHelicopter " << endl;
        Vehicle::get_details();
        cout << "Enter number of blades: ";
        cin >> number_of_blades;
        cout << "Enter lifting capacity(kg): ";
        cin >> lifting_capacity;
    }
    
    void print_details() override{
        cout << "\nHelicopter Details" << endl;
        Vehicle::print_details();
        cout << "Number of blades: " << number_of_blades << endl;
        cout << "Lifting capacity: " << lifting_capacity <<endl;
    }
    
    ~Helicopter(){
        cout << "Helicopter destructor call" << endl;
    }
    
};

class Truck : public Vehicle{
    float fuel_tank;
    
public:
    Truck(){
        cout << "Truck No args constructor executed" << endl;
        fuel_tank = 0.0f;
    }
    
    Truck(string company,string model,float cost,float lc)
        :Vehicle(model,company,cost){
        cout << "Truck args constructor executed" << endl;
        fuel_tank = lc;
    }
    
    void get_details () override{
        cout << "\nTruck " << endl;
        Vehicle::get_details();
        cout << "Enter fuel tank capacity(ltr): ";
        cin >> fuel_tank;

    }
    
    void print_details() override{
        cout << "\nTruck Details" << endl;
        Vehicle::print_details();
        cout << "Fuel Tank Capacity: " << fuel_tank << endl;
    }
    
    ~Truck(){
        cout << "Truck destructor call" << endl;
    }
};

class Bike : public Vehicle{
    string type;
    
public:
    Bike(){
        cout << "Bike No args constructor executed" << endl;
        type = "";
    }
    
    Bike(string company,string model,float cost,string ty)
        :Vehicle(model,company,cost){
        cout << "Bike args constructor executed" << endl;
        type = ty;
    }
    
    void get_details () override{
        cout << "\nBike " << endl;
        Vehicle::get_details();
        cout << "Type(Sports/cruiser): ";
        cin >> type;

    }
    
    void print_details() override{
        cout << "\nBike Details" << endl;
        Vehicle::print_details();
        cout << "Type: " << type << endl;
    }
    
    ~Bike(){
        cout << "Bike destructor call" << endl;
    }
    
};


int main(){
    
    Vehicle* v1 = new Electric_car();
    Vehicle* v2 = new Helicopter();
    Vehicle* v3 = new Truck();
    Vehicle* v4 = new Bike();
    
    v1->get_details();
    v2->get_details();
    v3->get_details();
    v4->get_details();
    
    v1->print_details();
    v2->print_details();
    v3->print_details();
    v4->print_details();
}