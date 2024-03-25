#include <iostream>
#include <sstream>
using namespace std;

int main ()
{
  string buffer;
  char operation;
  double a = 0, b = 0, result = 0;

  cout << "Enter formula: ";
  cin >> buffer;

  stringstream buffer_stream (buffer);
  buffer_stream >> a >> operation >> b;

  if (operation == '+') result = a + b;
  if (operation == '-') result = a - b;
  if (operation == '/') result = a / b;
  if (operation == '*') result = a * b;

  cout << "result: " << result << endl;
}
