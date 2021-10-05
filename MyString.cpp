#include <iostream>

using namespace std;

class MyString{
  char str[100];

public:

    void input();
    void show();
    int len();
    bool operator== (MyString strObj); // Equality
    void operator= (MyString strObj);  // Copy
    void operator+ (MyString strObj);  // Concat
    void operator<< (MyString strObj); // Show
    void operator>> (MyString strObj); // Reverse
    void operator~();                  // Palindrome
    bool operator/ (MyString strObj);  // Substr
};

void MyString::input(){
    cout << "Enter the string : ";
    cin.sync();
    cin.getline(str,100);
}

void MyString::show(){
    cout << str << endl;
}

int MyString::len(){
    int len{0};
    while(this->str[len]!='\0') len++;
    return len;
}

// Checking for equality 
bool MyString::operator==(MyString strObj){
    if(this->len() != strObj.len()) return false;
    
    for(int i=0 ; i < strObj.len() ; ++i){
        if(this->str[i] != strObj.str[i]) return false;
    }
    return true;
}

// Copying
void MyString::operator=(MyString strObj){
    int i{0};
    
    while(strObj.str[i]!='\0'){
        this->str[i] = strObj.str[i];
        ++i;
    }
    this->str[i] = '\0';
    cout << "String copied" <<endl;
}

// Concatenation
void MyString::operator+(MyString strObj){
    int i{0},j;

    if(this->len() + strObj.len()>100){
        cout << "Overflow" <<endl;
        return;
    }
    
    for( j=0 ; str[j]!='\0' ; ++j);
    
    for( i = 0 ; strObj.str[i]!='\0' ; ++i){
        str[j+i] = strObj.str[i];
    }
    str[i+j] = '\0';
}

void MyString::operator<<(MyString strObj){
    cout << strObj.str << endl;
}

// Reverse
void MyString::operator>>(MyString strObj){
    for(int i=strObj.len()-1 ; i>=0 ; --i) cout << strObj.str[i];
    
    cout << endl;
}

// Checking for palindrome
void MyString::operator~(){
    int i=0,j = this->len()-1;
    
    for(;i<this->len() && j>=0 ;++i,--j){
        if(str[i]!=str[j]){
            cout << "Not a palindrome" << endl;
            return;
        }
    }
    cout << "It is a palindrome." << endl;
}

// StrStr
bool MyString::operator/(MyString strObj){
    for(int i=0 ; i < len() - strObj.len()+1 ; ++i){
        if(str[i] == strObj.str[0]){
            for(int j = 0 ; j < strObj.len() ; ++j){
                if(str[i+j] != strObj.str[j]) break;
                if(str[i+j] == strObj.str[j] && j == strObj.len() - 1) return true;
            }
        }
    }
    return false;
}


int main()
{
    int choice=1;
    bool f;

    MyString str1,str2;

    while(choice==1 && choice!=8)
    {

    // menu 
    cout<<"\nMain Menu\n\t1.Equality\n\t2.String Copy\n\t3.Concat";
    cout<<"\n\t4.Show\n\t5.Reverse\n\t6.Palindrome\n\t7.Sub String";
    cout<<"\n\t8.Exit\n"<<endl;
    cout<<"Enter your choice:";

    cin>>choice;

    switch(choice)
    {
        case 1:
            cout<<"\n1st string-\n";
            str1.input();
            cout<<"\n2nd string-\n";
            str2.input();
            
            f = str1 == str2;
            if(f==true)
                cout<<"\nBoth Strings are Equal\n";
            else
                cout<<"\nStrings are not Equal\n";
            break;
            
        case 2:
            str2.input();
            // Copying
            str1 = str2;
            cout << "Copied String : ";
            str1.show();
            break;
            
        case 3:  
            cout<<"\n1st string-\n";
            str1.input();
            cout<<"\n2nd string-\n";
            str2.input();
            // Concat
            str1+str2;
            cout << "Concatenated String : ";
            str1.show();
            break;
            
        case 4:
            str1.input();
            str2 << str1;
            break;
            
        case 5:
            str1.input();
            
            // Reverse
            str2>>str1;
            break;
             
        case 6:
            str1.input();

            //check for palindrome
            ~str1;
            break;
             
        case 7:
            cout<<"\nEnter the Main string\n";
            str1.input();
            cout<<"\nEnter the other string\n";
            str2.input();
            
            // Finding substring
            f = str1 / str2;
            
            if(f==1)
                cout<<"\n Is a Substring\n";
            else
                cout<<"\nNot a substring\n";
 
            break;
            
        case 8: return 0;
        
        default: cout<<"Invalid choice\n";
      } 
       if(choice!=8){
       cout<<"\n\n\tDo you want to continue(Press 1 to continue)";
       cin>>choice;
       }
     }
 
    return 0;
}