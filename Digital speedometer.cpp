#include <iostream>
using namespace std;

int main ()
{
  char speed_str[6];
  double speed_delta, speed_value = 0;

  do
  {
    cout << "Speed delta: ";
    cin >> speed_delta;

    if (speed_delta + speed_value > 150)
    {
      cout << "Incorrect value" << endl;
      continue;
    }

    if (speed_value == 0)
      cout << "*Run" << endl;

    speed_value += speed_delta;

    if(speed_value < 1)
    {
      cout << "*Stop " << endl;
      break;
    }

    sprintf (speed_str, "%.1f", speed_value);
    cout << "Speed: " << speed_str << endl;

  } while (1);
}
