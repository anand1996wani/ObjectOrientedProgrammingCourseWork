/*
	This file contains the main function..
*/

#include <iostream>
#include <fstream>
#include "Complex.h"
#include <vector>
using namespace std;
int main(){
  fstream input_file;
  input_file.open("ComplexList.txt");
  vector<Complex> vec;
  char a;
  float b,c;
  while (input_file >> a >> b >> c){
    Complex obj(a,b,c);
    vec.push_back(obj);
  }
  int choice;
  while(true){
    cout<<"\n1 : Display file contents\n";
    cout<<"2 : Addition operation\n";
    cout<<"3 : Subtraction operation\n";
    cout<<"4 : Multiplication operation\n";
    cout<<"5 : Division operation\n";
    cout<<"6 : Unary operator -\n";
    cout<<"7 : Sum of all complex number stored in the vector\n";
    cout<<"8 : equation:   A = - B*(C-D)/E \n";
    cout<<"9 : Exit \n";
    cin>>choice;
    Complex c,c1,c2;
    vector<Complex>::iterator v = vec.begin();
    Complex obj,obj1;
    Complex A,B,C,D,E;
    switch(choice){
    case 1:
      cout<<" Polar \t\t\t Rectangular "<<endl;
      while(v!=vec.end()){
	obj = *v;
	obj.print();
	v++;
      }
      break;
    case 2:
      cout<<"Addition operation\n";
      cout<<"Enter first number\n";
      c1.input();
      cout<<"Enter second number\n";
      c2.input();
      c = c1 + c2;
      cout<<"Result of addition is :\n";
      c.result();
      break;
    case 3:
      cout<<"Subtraction operation\n";
      cout<<"Enter first number\n";
      c1.input();
      cout<<"Enter second number\n";
      c2.input();
      c = c1 - c2;
      cout<<"Result of Subtraction is :\n";
      c.result();
      break;
    case 4:
      cout<<"Multiplication operation\n";
      cout<<"Enter first number\n";
      c1.input();
      cout<<"Enter second number\n";
      c2.input();
      c = c1 * c2;
      cout<<"Result of Multiplication is :\n";
      c.result();
      break;
    case 5:
       cout<<"Division operation\n";
      cout<<"Enter first number\n";
      c1.input();
      cout<<"Enter second number\n";
      c2.input();
      c = c1 / c2;
      cout<<"Result of Division is :\n";
      c.result();
      break;
    case 6:
      cout<<"Unary subtraction operation\n";
      cout<<"Enter first number\n";
      c1.input();
      c = c1.operator-();
      cout<<"Result of Unary subtraction is :\n";
      c.result();
      break;
    case 7:
      cout<<"Sum of all complex number stored in the vector\n";
      while(v!=vec.end()){
       obj = *v;
       obj1 = obj1 + obj;
       v++;
      }
      obj1.result();
      break;
    case 8:
      cout<<"Enter value of B\n";
      B.input();
      cout<<"Enter value of C\n";
      C.input();
      cout<<"Enter value of D\n";
      D.input();
      cout<<"Enter value of E\n";
      E.input();
      A = (B*(C-D)/E);
      A.result();
      break;
    case 9:
      break;
    }
    if(choice==9)
      break;
  }
  
  return 0;
}
