#include <iostream>
#include <string>

class Student{
private:
    std::string name;
    std::string rollno;
    std::string class_name;
    
    class Subject{
        public:
        std::string subject_code;
        std::string sub_name;
        int marks_got;
    };
    
    Subject subjects[3];
    
    int marks_obtained;
    int max_marks;
    float perc;
    
public:

    //Paramaterized constructor

    Student (std::string sname,std::string srollno,std::string sclass_name) {
        name = sname;
        rollno = srollno;
        class_name = sclass_name;
        marks_obtained = 0;
        max_marks = 300;
        perc = 0;
    }

    //No Parameter default constructor

    Student () {
        name = "";
        rollno =  "";
        class_name = "";        
        marks_obtained = 0;
        max_marks = 300;
        perc = 0;
    }

    char get_grade(){
        perc = (marks_obtained / (float)max_marks)*100;

        if(perc >= 75){
            return 'A';
        }

        else if(perc >=60 && perc < 75){
            return 'B';
        }
        else if(perc >=45 && perc < 60){
            return 'C';
        }
        else if(perc >=35 && perc < 45){
            return 'D';
        }
        else{
            return 'F';
        }
    }
    
    void set_subjects(){
        for(int i=0;i<3;++i){
            std::cout<<"Enter subject name , subject code and marks obtained "<<"for subject "<< i+1 <<"\n";
            std::cin>>subjects[i].sub_name>>subjects[i].subject_code>>subjects[i].marks_got;
            marks_obtained += subjects[i].marks_got;
        }
        
    }
    
    void print_details(){
        std::cout<<name<<"\t"<<rollno<<"\t"<<class_name<<"\t"<<marks_obtained<<"\t\t"<<max_marks<<"\t\t"<<get_grade()<<std::endl;
    }
};

using namespace std;

int main(){
    int n;
    string name,rollno,class_name;
    
    Student students[100];
    
    cout << "Enter the number of students: ";
    cin >> n;
    
 for (int i=0;i<n;++i){
        cout<<"\nEnter name, rollno, class for student "<<i+1<<endl;
        cin>>name>>rollno>>class_name;
        students[i] = Student(name,rollno,class_name);
        students[i].set_subjects();
       }
    cout<<"\n\nName\tRollNo\t\tClass\tMarks Obtained\tMax Marks\tGrade\n";
    for(int i=0;i<n;++i){
        students[i].print_details();
    }
    cout<<"\n\n";
    return 0;
}
