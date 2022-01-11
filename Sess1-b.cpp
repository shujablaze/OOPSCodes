#include<iostream>

using namespace std;

class Matrix
{
 int **mat;
 int row;
 int col;

 public:

  //default constructor
  Matrix()
  {
   mat=NULL;
   row=0;
   col=0; 
  }

  //parameter constructor
  Matrix(int order)
    {

   int i,j;
   mat=(int **)new int[order];
   row=order;
   col=order;
   
   for(i=0;i<order;i++)
        mat[i]=new int[order];

   for(i=0;i<order;i++)
        for(j=0;j<order;j++)
            mat[i][j]=0;
    }
    
    // Overloaded + for addition of two matrix
    Matrix operator +(Matrix x)
    {
        Matrix temp(this->col);
        
        for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                        temp.mat[i][j] = mat[i][j] + x.mat[i][j];
                }
        }
        return temp;
    }
    
    // Overloaded + for subtraction of two matrix
    Matrix operator -(Matrix x)
    {
        Matrix temp(this->col);
        
        for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                        temp.mat[i][j]=mat[i][j]-x.mat[i][j];
                }
        }
        return temp;
    }
    
    
    // Overloaded * for mutplying a scaler value to matrix
    void operator *(int value)
    {
        for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                        mat[i][j]=mat[i][j]*value;
                }
        }
    }
    
    // Overloaded == for equality between two matrices
    bool operator ==(Matrix m)
    {
        for(int i=0; i<3; i++)
        {
                for(int j=0; j<3; j++)
                {
                    if(mat[i][j] != m.mat[i][j])
                       return false;
                }
        }
        return true;
    }
    
    //Overloaded ~ for transpose of a matrix
    Matrix operator~(){
        Matrix transposed(3);
        
        for (int i = 0; i < col; ++i)
            for (int j = 0; j < row; ++j) {
                transposed.mat[j][i] = mat[i][j];
            }
    return transposed;
    }
    
    friend istream& operator>>(istream &cin,Matrix &m);

    friend ostream& operator<<(ostream &cout,Matrix &m);
};

// overloaded >> to input matrix
istream& operator>>(istream &in,Matrix &c)
{

 int i,j;
 cout<<"\nEnter the matrix"<<endl;
 for(i=0;i<c.row;i++)
 {
  for(j=0;j<c.col;j++){
   cout<<"\nEnter value for [" << i << "][" << j << "]";
   in>>c.mat[i][j];
  }
 }
 return in;
}

// overloaded << for output
ostream& operator<<(ostream &cout,Matrix &c)
{

 int i,j;
 cout<<"\nMatrix"<<endl;
 for(i=0;i<c.row;i++)
 {
  for(j=0;j<c.col;j++){
   cout<<c.mat[i][j]<<" ";
  }
  cout << "\n";
 }
 return cout;
}

int main(){
    int choice;
    Matrix m1(3);
    Matrix m2(3);
    Matrix m3(3);
    
    // Helper variables
    int id;

    
    while(true){
        cout << "\nMatrix" << endl;
        cout << "1.Add\n2.sub\n3.Multiply\n4.Transpose\n5.Print\n6.Insert\n7.Equate"<<endl;
        cin >> choice;
        switch(choice){
            case 1:
                m3 = m1+m2;
                cout << m3;
                
                break;
            
            case 2:
                m3 = m1 - m2;
                cout << m3;
                break;
            
            case 3:
                m2 * 2;
                cout << "Multiplied" << endl;
                cout << m2;
                break;
                
            case 4:
                m3 = ~m2;
                cout << "transposed" << endl;
                cout << m3;
                break;
            
            case 5:
                cout << "M1" << endl;
                cout << m1;
                
                cout << "M2" << endl;
                cout << m2;
                
                cout << "M3" << endl;
                cout << m3;
                break;
                
            case 6:
                cout << "M1";
                cin >> m1;
                
                cout << "M2";
                cin >> m2;
                break;
                
            case 7:
                cout << "M1";
                cin >> m1;
                
                cout << "M2";
                cin >> m2;
                
                if(m1==m2) cout << "equal";
                else cout << "Not equal";
                break;
                
            default:
                cout << "Invalid Choice" << endl;
                break;
        }
    }
}