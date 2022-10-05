/// @file Pi.cpp
/// @brief Computes value of pi
/// @author Kentaro Matsuo
#include <cfloat>
#include <cmath>
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
int main()
{
  double pi;
  double p = 0;
  double n;
  cout << "Please enter a digit for n: \n";
  cin >> n;
  
  for (int i = 0; i < n; i++)
  {
    p += pow(-1,i)/(2.0 * i + 1);
  }
  pi = 4 * p;
  cout	<< setprecision(DBL_DIG) << "PI (approx): " << pi	<< "; n: "	<< n	<< endl;
  cout	<< "PI (actual): " << "3.141592653589793" << endl;
  cout	<< "Decimal digits of precision: " << DBL_DIG << endl;
  cout	<< "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
  cout	<< "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793,	3.14)	<< endl;
}
