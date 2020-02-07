#ifndef MATRIX_H
#define MATRIX_H
#include <iostream>
using namespace std;
class Matrix {
  public:
   // Construction
   Matrix(int r = 0, int c = 0, double d = 0.0);
   // Copy construction
   Matrix(const Matrix& m);
   // Destructor
   ~Matrix();
   // Index operators
   const double& operator()(int i, int j) const; //to work on const objects
   double& operator()(int i, int j);
   // Copy assignment operator
   Matrix& operator=(const Matrix& m);
   // Compound arithmetic operators
   Matrix& operator+=(const Matrix& x);
   Matrix& operator-=(const Matrix& x);
   Matrix& operator*=(const Matrix& m);
   Matrix& operator*=(double d); // scalar multiplication
   // Output
   void print(ostream& sout) const; //display the matrix onto output stream
   // sout neatly
   int ncols() const; //return the number of columns
   int nrows() const; // return the number of rows
  private:
   int rows; // number of rows
   int cols;  // number of columns
   double *element; //dynamic array to hold  data
};
// Arithmetic operators are not members
Matrix operator+(const Matrix&l, const Matrix&r); // return   l+r
Matrix operator-(const Matrix&l, const Matrix&r);  // return l-r
Matrix operator*(const Matrix&l, const Matrix&r); //  return l*r
Matrix operator*(double d, const Matrix& r);          // return d*l
Matrix operator*(const Matrix& m, double d);        // return l*d
// Overloaded stream insertion operator
ostream& operator<<(ostream& out, const Matrix& x);
#endif
