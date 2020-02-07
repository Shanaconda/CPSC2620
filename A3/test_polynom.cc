//*************************************************************************
// CPSC2620 Fall 2019
// Assignment #3
// File: polynom.cc
// Implementation of a simple polynomial class of degree n
// Author: Arie Bomhof
// Date: Oct. 25, 2019
//*************************************************************************

#include"./polynom.h"
#include<iostream>
#include<vector>
using namespace std;

int main()
{
   vector<int> v1,v2,v3;
   v1.push_back(4);
   v1.push_back(2);
   v1.push_back(-1);
   v1.push_back(2);
   v1.push_back(0);
   v1.push_back(0);
   v1.push_back(2);
   v2.push_back(-4);
   v2.push_back(0);
   v2.push_back(1);
   
   Polynom p1(v1);
   Polynom p2(v2);
   Polynom p3(v3);
   Polynom p4;
   
   
   cout << "p1 is: " << p1 << endl;
   cout << "p2 is: " << p2 << endl;
   cout << "p3 is: " << p3 << endl;
   cout << "p4 is: " << p4 << endl;
   
   cout << "p1(3) = " << p1(3) << endl;
   cout << "p2(3) = " << p2(3) << endl;
   
   Polynom p5;
   p5 = p1 + p2;
   cout << "p5 after p5 = p1 + p2 is: " << p5 << endl;
   
   cout << "Enter new coefficients for p5, (CTRL-D to stop): ";
   cin >> p5;
   cout << "p5 is now " << p5 << endl;
   
   Polynom p6;
   cout << "Enter coefficients for p6, (CTRL-D to stop): ";
   cin >> p6;
   cout << "p6 is: " << p6 << endl;
   
   p6 = p2-p1;
   cout << "After p6 = p2-p1, p6 is: " << p6 << endl;
   
   p6 = p1-p1;
   cout << "After p6 = p1-p1, p6 is: " << p6 << endl;
   
   if(p1.setCoeff(2,-9999))
   cout << "After \"p1.setCoeff(2,-9999)\" p1's coefficient of degree 2 is"
     << " changed to -9999" << endl;
   else
     cout << "After \"p1.setCoeff(2,3)\" no change made to p1." << endl;
   cout << "p1 is: " << p1 << endl;
   
   if(p1.setCoeff(8,3))
      cout << "After \"p1.setCoeff(8,3)\" p1's coefficient of degree 8 is"
   	   << " changed to 3" << endl;
   else
      cout << "After \"p1.setCoeff(8,3)\" no change made to p1." << endl;
   cout << "p1 is: " << p1 << endl;

   int t;
   if(p1.getCoeff(1,t))
      cout << "The coefficient associated with the first degree term of "
	   << "p1 is " << t << endl;
   else
      cout << "The first degree coefficient does not exist" << endl;

   if(p1.getCoeff(2,t))
      cout << "The coefficient associated with the second degree term of "
	   << "p1 is " << t << endl;
   else
      cout << "The second degree coefficient does not exist" << endl;

   if(p1.getCoeff(8,t))
      cout << "The coefficient associated with the eighth degree term of "
	   << "p1 is " << t << endl;
   else
      cout << "The eighth degree coefficient does not exist" << endl;
   
   
   return 0;

}
