#include <iostream>
#include <cmath>
using namespace std;

int main ()
{
  string str1, str2;
  double result, integer, mantissa;

  cout << "Enter Integer: "; cin >> str1;
  cout << "\nEnter Mantissa: "; cin >> str2;

  integer = stod (str1);
  mantissa = stod (str2);

  while (abs(mantissa) > 1)
  {
    mantissa /= 10;
  }

  if (integer < 0 && mantissa > 0 || integer > 0 && mantissa < 0)
    result = -(abs(integer) + abs(mantissa));
  else
    result = integer + mantissa;

  cout << "\nResult: " << result << endl;
}
