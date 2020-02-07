#ifndef TRIANGULARMATRIX_H
#define TRIANGULARMATRIX_H

#include"structuredMatrix.h"
#include<iostream>

using namespace std;

//Derived class from structuredMatrix
class Triangular_Matrix: public Structured_Matrix {
   
  public:
   //Default Constructor
   Triangular_Matrix(int r=0, double d=0);

   //Deconstructor
   ~Triangular_Matrix();

   //Sum of Rows (Pure Virtual)
   virtual double infnorm()=0;

   
   //Index Operator
   const double& operator()(int i, int j) const;
   double& operator()(int i, int j);

   
   //Print Function(Pure virtual)
   virtual void print()=0;
 
};
#endif
   

      







   
