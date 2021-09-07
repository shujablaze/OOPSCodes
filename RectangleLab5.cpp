#include <iostream>

using namespace std;

class Rectangle{
    float length;
    float width;
    
public:
    void set_length(float len){
        length = len;
    }
    
    void set_width(float wdth){
        width = wdth;
    }
    
    float perimeter(){
        return 2*(length+width);
    }
    
    float area(){
        return (length * width);
    }
    
    void show(){
        cout << "This rectangle has length of " << length << " and width of " << width << endl; 
    }
    
    int same_area(Rectangle rhs){
        return ((this->area() - rhs.area()) > 1e-15)? 1 : 0;
    }
};

int main(){
    Rectangle r1,r2;
    
    r1.set_length(5);
    r1.set_width(2.5);
    
    r2.set_length(5);
    r2.set_width(18.9);
    
    cout << "Rectangle 1 : " ;
    r1.show();
    cout << "Perimeter of rectangle 1 is " << r1.perimeter() << endl;
    cout << "Area of rectangle 1 is " << r1.area() << endl;
    
    cout<<"\n";
    
    cout << "Rectangle 2 : " ;
    r2.show();
    cout << "Perimeter of rectangle 2 is " << r2.perimeter() << endl;
    cout << "Area of rectangle 2 is " << r2.area() << endl;
    
    if(r1.same_area(r2)) cout << "\nBoth rectangles have same area." << endl;
    else cout << "\nThe two rectangles have different area." <<endl;
    
    r1.set_length(15);
    r1.set_width(6.3);
    cout<<"\n---------------------------------------------------\n\n";
    
    cout << "Rectangle 1 : " ;
    r1.show();
    cout << "Perimeter of rectangle 1 is " << r1.perimeter() << endl;
    cout << "Area of rectangle 1 is " << r1.area() << endl;
    
    cout<<"\n";
    
    cout << "Rectangle 2 : " ;
    r2.show();
    cout << "Perimeter of rectangle 2 is " << r2.perimeter() << endl;
    cout << "Area of rectangle 2 is " << r2.area() << endl;
    
    if(r1.same_area(r2)) cout << "\nBoth rectangles have same area." << endl;
    else cout << "\nThe two rectangles have different area." <<endl;
    
}