/*
	This files defines all the functions defined in Complex.h
	
*/

#include "Complex.h"
#include <iostream>
using namespace std;
Complex :: Complex()
{
    r_c = 'r';//r for  real
    num_1 = 0;
    num_2 = 0;
}
Complex :: Complex(char r)
{
    r_c = r;
    if(r_c == 'r'){
      num_1 = 0;
      num_2 = 0;
    }
    else{
      num_1 = 0;
      num_2 = 1;
    }
}
Complex :: Complex(char r,float a,float b){
  r_c = r;
  num_1 = a;
  num_2 = b;
}
void Complex :: print(){
/*	
	This function is used to print numbers read from file in polar and rectangular form..
*/
  if(r_c=='p'){
    cout<<num_1<<"\t"<<num_2<<"\t\t"<<num_1*sin(num_2)<<" + j"<<num_1*cos(num_2)<<endl;
  }
  else{
    cout<<sqrt(pow(num_1,2) + pow(num_2,2))<<"\t"<<atan(num_2/num_1)<<"\t\t"<<num_1<<" + j"<<num_2<<endl;
  }
}
void Complex :: input(){
/*
	This function is used to take input of Complex objects for performing operations..
*/
  cout<<"p : polar co-ordinates\t r : rectangular co-ordinates\n";
  cout<<"select polar or rectangular for number\n";
  cin>>this->r_c;
  cout<<"Enter real part of number\n";
  cin>>this->num_1;
  cout<<"Enter the imaginary part of  number\n";
  cin>>this->num_2;
}
void Complex :: result(){
/*
	This functions is used to print Complex result in polar and rectangular form..
*/
  cout<<" Rectangular \t\t Polar  "<<endl;
  if(this->num_2 < 0){
    cout<<this->num_1<<" - j"<<-1*this->num_2<<"\t\t"<<sqrt(pow(num_1,2) + pow(num_2,2))<<"\t"<<atan(num_2/num_1)<<endl;
  }
  else{
    cout<<this->num_1<<" + j"<<this->num_2<<"\t\t"<<sqrt(pow(num_1,2) + pow(num_2,2))<<"\t"<<atan(num_2/num_1)<<endl;
  }
}

Complex Complex :: operator + (Complex b){
/*
	Addition of Complex numbers..
*/
  Complex c,c1,c2;
  c1.r_c = this->r_c;
  c1.num_1 = this->num_1;
  c1.num_2 = this->num_2;
  c1 = convert_polar_to_rectangle(c1);
  c2 = convert_polar_to_rectangle(b);
  c.num_1 = c1.num_1 + c2.num_1;
  c.num_2 = c1.num_2 + c2.num_2;
  return c;
}
Complex Complex :: operator - (Complex b){
  Complex c,c1,c2;
  c1.r_c = this->r_c;
  c1.num_1 = this->num_1;
  c1.num_2 = this->num_2;
  c1 = convert_polar_to_rectangle(c1);
  c2 = convert_polar_to_rectangle(b);
  c.num_1 = c1.num_1 - c2.num_1;
  c.num_2 = c1.num_2 - c2.num_2;
  return c;
}
Complex Complex :: operator * (Complex b){
  Complex c,c1,c2;
  c1.r_c = this->r_c;
  c1.num_1 = this->num_1;
  c1.num_2 = this->num_2;
  c1 = convert_polar_to_rectangle(c1);
  c2 = convert_polar_to_rectangle(b);
  c.num_1 = (c1.num_1*c2.num_1)-(c1.num_2*c2.num_2);
  c.num_2 = (c1.num_1*c2.num_2)+(c1.num_2*c2.num_1);
  return c;
}
Complex Complex :: operator / (Complex b){
  Complex c,c1,c2;
  c1.r_c = this->r_c;
  c1.num_1 = this->num_1;
  c1.num_2 = this->num_2;
  c1 = convert_polar_to_rectangle(c1);
  c2 = convert_polar_to_rectangle(b);
  c.num_1 = ((c1.num_1*c2.num_1)+(c1.num_2*c2.num_2))/((pow(c2.num_1,2)) + (pow(c2.num_2,2)));
  c2.num_2 = ((c1.num_2*c2.num_1)-(c1.num_1*c2.num_2))/((pow(c2.num_1,2)) + (pow(c2.num_2,2))); 
  return c;
}
Complex Complex :: operator - (){
  Complex c,c1;
  c1.r_c = this->r_c;
  c1.num_1 = this->num_1;
  c1.num_2 = this->num_2;
  c1 = convert_polar_to_rectangle(c1);
  c.num_1 = -1*c1.num_1;
  c.num_2 = -1*c1.num_2;
  return c;
}
Complex Complex :: convert_polar_to_rectangle(Complex a){
/*
	This is used to convert polar to rectangle .. 
*/
  Complex c;
  if(a.r_c=='p'){
    c.num_1 = a.num_1*cos(a.num_2);
    c.num_2 = a.num_1*sin(a.num_2);
  }
  else{
    c.num_1 = a.num_1;
    c.num_2 = a.num_2;
  }
  return c;
}
