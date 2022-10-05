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
  double p = 0;
  double n = 1048576;

  for (int i = 2; i < n; i *=2)
  {
    for (int k = 0; k < i; k++)
    {
      p += pow(-1,k)/(2.0 * k + 1);
    }
    cout	<< setprecision(DBL_DIG) << "PI: " << 4 * p	<< "; n: "	<< i	<< endl;
    p=0;
  }
}
