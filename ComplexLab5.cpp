#include <iostream>

using namespace std;

class Complex{
    float real;
    float imaginary;
    
public:
    friend Complex sum(Complex lhs,Complex rhs);
    void set(float r,float i){
        real = r;
        imaginary = i;
    }
    
    void display(){
        cout<<real<<" + "<<imaginary<<"i" <<endl;
    }
};

Complex sum(Complex lhs,Complex rhs){
    Complex ans;
    ans.set(lhs.real+rhs.real,lhs.imaginary+rhs.imaginary);
    return ans;
}

int main(){
    Complex c1,c2,c3;
    
    c1.set(5,15);
    c2.set(3.7,2.5);
    
    cout<<"Complex number 1 : ";
    c1.display();
    
    cout<<"Complex number 2 : ";
    c2.display();
    
    c3 = sum(c1,c2);
    
    cout<<"Sum of two numbers: ";
    c3.display();
}