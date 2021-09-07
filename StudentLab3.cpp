#include <iostream>

using namespace std;

class Student{
private:
    int student_id;
    char name[30] ;
    int marks;

public:
    void getStudent(){
        cout << "Enter student id: ";
        cin >> student_id;
        cout << "Enter student name: ";
        cin >> name;
        cout << "Enter student marks: ";
        cin >> marks;
    }
    void printStudent(){
        cout << student_id << "\t\t\t" << name << "\t\t" << marks << endl;
    }
};

int main(){
    short n;
    Student students[10];
    
    cout << "Enter the number of students (MAX 10) : ";
    cin >> n;
    
    for(short i=0;i<n;++i){
        cout << "\nEnter the details of student " << i+1 << endl;
        students[i].getStudent();
    }
    
    cout << "\n\nSTUDENT DETAILS\n" << endl;
    cout << "Student ID\t\tName\t\tMarks" << endl;
    
    for(short i=0;i<n;++i) students[i].printStudent();
    
    return 0;
}