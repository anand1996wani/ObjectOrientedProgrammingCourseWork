#include <math.h>
class Complex{
  char r_c;
  float num_1;
  float num_2;
 public:
  Complex();
  Complex(char r);
  Complex(char r,float a,float b);
  void print();
  void result();
  void input();
  Complex convert_polar_to_rectangle(Complex a);
  Complex operator + (Complex b);
  Complex operator - (Complex b);
  Complex operator * (Complex b);
  Complex operator / (Complex b);
  Complex operator - ();
};
