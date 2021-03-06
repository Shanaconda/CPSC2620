#include"matrix.h"
#include<iostream>
#include<iomanip>
#include<cassert>

using namespace std;

//*******************************************
//Default Constructor
//Stores values in a single dimensional array
//******************************************
Matrix::Matrix(int r, int c, double d)
{
   //Storing date 
   rows=r;
   cols=c;
   
   //Pointer to private data member
   element=new double[rows*cols];

   //Storing the values into d

   for(int i=0; i<rows*cols; i++)
   {
      element[i]=d;

   }
}
//*********************************************
//Copy Constructor
//Takes in a Matrix and output a copy of it
//*********************************************
Matrix::Matrix(const Matrix& m)
{
   //Intializing 
   rows=m.rows;
   cols=m.cols;

   //new pointer element 
   element=new double[m.rows*m.cols];

   //Loop to copy values
   for(int i=0; i<m.rows*m.cols; i++)
   {
      element[i]=m.element[i];

   }
}
//*********************************************
//Copy assignment operator
//Peforms deep copy 
//*********************************************
Matrix& Matrix::operator=(const Matrix& m)
{
   if(this!=&m)
   {
      delete[] element; //Delete old storage
      rows=m.rows;
      cols=m.cols;

      //New pointer element 
      element= new double[m.rows*m.cols];

      //Copying elements
      if(element!=NULL)
	 for(int i=0; i<m.rows*m.cols; i++)
	 {
	    element[i]=m.element[i];
	 }

   }
   return *this;
}
//*****************************************************
//Destructor
//Release the dynamic memory held by the matrix object
//*****************************************************
Matrix::~Matrix()
{
   //Deletes data
   delete[] element;
   element=NULL;
}

//******************************************************
//Index access operator
//******************************************************
double& Matrix::operator()(int i, int j)
{return this->element[(i*cols)+j];}
//*****************************************************
//Index access operator
//***ISSUES WITH THIS 
//****************************************************
const double& Matrix::operator()(int i, int j) const 
{return this->element[(i*cols)+j];}
//*****************************************************
//Matrix operator +=
//Overloaded + operator
//*****************************************************
Matrix& Matrix::operator+=(const Matrix& x)
{
   assert(rows==x.rows&& cols==x.cols);

   for(int i=0; i<rows*cols; i++)
   {
      element[i]+=x.element[i];

   }
   return *this;
}
//*****************************************************
//Matrix operator-=
//Overloaded subtraction operator
//*****************************************************
Matrix& Matrix::operator-=(const Matrix& x)
{
   assert(cols==x.cols&&rows==x.rows);
   
   for(int i=0; i<rows*cols; i++)
   {
      element[i]-=x.element[i];
   }

   return *this;
}
//*****************************************************
//Matrix operator *=
//Overloaded * operator 
//*****************************************************
Matrix& Matrix::operator*=(const Matrix& m)
{
   //Checking if cols is equal to m.rows
   assert(cols==m.rows);

   //Creating a temp Matrix 
   Matrix temp(rows, m.cols, 0.0);

   for(int i=0; i<rows; i++)
   {
      for(int j=0; j<m.cols; j++)
      {
	 for(int k=0; k<cols; k++)
	 {
	    temp(i,j)+=(*this)(i,k)*m(k,j);
	 }

      }

   }

   *this=temp;
   return *this;
   
}
   

//*****************************************************
//Scalar multiplication
//Overloaded * operator using a double value 
//*****************************************************
Matrix& Matrix::operator*=(double d)
{
   for(int i=0; i<rows*cols; i++)
   {
      element[i]*=d;

   }

   return *this;
}
//*****************************************************
//Display the matrix output stream
//*****************************************************
void Matrix::print(ostream& sout)const
{
   int index=rows*cols;

   cout<<"| ";
   for(int i=0; i<index;i++)
   {
      if((i%cols)==0&& i!=0)
      {
   
      sout<<" |"<<endl;
      sout<<"| ";
      }
      sout<<setw(5)<<element[i];      
   }
cout<<" |";
cout<<endl;

}
//*****************************************************
//Return the number of columns
//*****************************************************
int Matrix::ncols()const{return cols;}

//*****************************************************
//Return the number of rows
//*****************************************************
int Matrix::nrows()const{return rows;}

//*****************************************************
//Additon Operator 
//*****************************************************
Matrix operator+(const Matrix&l, const Matrix&r)
{
   Matrix temp(l);
   return temp+=r;
}
//*****************************************************
//Subtraction Operator
//*****************************************************
Matrix operator-(const Matrix&l, const Matrix&r):  matrix temp(l)
{
   
   return temp-=r;
}
//*****************************************************
//Multiplcation operator
//*****************************************************
Matrix operator*(const Matrix&l, const Matrix&r)
{
   Matrix temp(l);
   return temp*=r;
}
//*****************************************************
//Multiplication operator
//
//*****************************************************
Matrix operator*(double d, const Matrix& r)
{
   Matrix temp(r);
   return temp*=d;

}
//*****************************************************
//Multiplcation operator
//*****************************************************
Matrix operator*(const Matrix& m, double d)
{
   Matrix temp(m);
   return temp*=d;
}
//*******************************************************
//Overloaded stream insertion operator
//*******************************************************
ostream& operator<<(ostream& out, const Matrix& x)
{
   x.print(out);
   return out;
}
