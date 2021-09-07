#include <iostream>
#include <cmath>

using namespace std;

class Distance{
    int feet;
    float inches;
    
public:
    
    friend Distance add(Distance lhs,Distance rhs);

    void set(int f,float i){
        feet = f;
        inches = i;
    }
    
    void display(){
        cout << feet <<" feets and " << inches << " inches." << endl;
    }
};

Distance add(Distance lhs,Distance rhs){
    Distance out;
    
    out.feet = lhs.feet + rhs.feet;
    
    if(lhs.inches+rhs.inches<12){
        out.inches = lhs.inches + rhs.inches;
    }else{
        out.inches = fmod(lhs.inches + rhs.inches , 12);
        out.feet += ((int)(lhs.inches + rhs.inches)) / 12;
    }
    return out;
}

int main(){
    Distance d1,d2,d3;
    
    d1.set(12,3.7);
    d2.set(8,5.8);
    
    cout<<"Distance 1 : ";
    d1.display();
    
    cout<<"Distance 2 : ";
    d2.display();
    
    d3 = add(d1,d2);
    
    cout << "\nSum of distances : ";
    d3.display();
}