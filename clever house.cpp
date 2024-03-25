#include <iostream>
#include <sstream>
#include <string>
using namespace std;

enum switches
{
  LIGHTS_INSIDE = 1,
  LIGHTS_OUTSIDE = 2,
  HEATERS = 4,
  WATER_PIPE_HEATING = 8,
  CONDITIONER = 16
};

int main ()
{
  string mv, li, state;
  int ot = 0, it = 0, day = 0, time = 0, sw_state = 0, color = 0;

  while (day != 2 && ot != -1)
  {
    cout << "--------------------------------------" << endl;
    cout << time << ".00 " << endl;

	cout << "t_inside, t_outside, movement, lights:\n" << endl;
    getline (cin, state); cout << endl;

	stringstream state_stream (state);
    state_stream >> ot >> it >> mv >> li;

    if (li == "y") { sw_state |= LIGHTS_INSIDE;
      if (sw_state & LIGHTS_INSIDE)
      { cout << "lights_inside: on" << endl; }
    }
    if ( (li == "n") && (sw_state & LIGHTS_INSIDE) )
    { sw_state &= ~LIGHTS_INSIDE;
      cout << "lights_inside: off" << endl;
	}

    if (time >= 16 || time <= 5)
    {
      if (mv == "y") { sw_state |= LIGHTS_OUTSIDE; }
      if (sw_state & LIGHTS_OUTSIDE) {
        if (mv == "n" || time == 5)
        { sw_state &= ~LIGHTS_OUTSIDE;
          cout << "lights_outside: off" << endl; }
        else
          cout << "lights_outside: on" << endl; }
    }

    if (it < 22) { sw_state |= HEATERS; }
    if (sw_state & HEATERS) {
      if (it >= 25) { sw_state &= ~HEATERS;
        cout << "heaters: off" << endl; }
      else {
        cout << "heaters: on" << endl; }
    }

    if (ot < 0 && ot != -1)
    { sw_state |= WATER_PIPE_HEATING; }
    if (sw_state & WATER_PIPE_HEATING) {
      if (ot >= 5) { sw_state &= ~WATER_PIPE_HEATING;
      cout << "water_pipe_heating: off" << endl; }
      else
      cout << "water_pipe_heating: on" << endl;
    }

    if (it >= 30) { sw_state |= CONDITIONER; }
    if (sw_state & CONDITIONER) {
      if (it <= 25) { sw_state &= ~CONDITIONER;
        cout << "conditioner: off" << endl; }
      else {
        cout << "conditioner: on" << endl; }
    }

    if (time <= 16) { color = 5000; }
    if (time > 16 && time <= 20) { color -= 575; }
    if (sw_state & LIGHTS_INSIDE)
    { cout << "Color temperature: " << color  << "K" << endl; }

    time++;
    if (time == 24) { day++; time = 0.00; }
  }
  cout << "\n--------------------------------------" << endl;
  if (time == 0)
    cout << time << ".00 " << endl;
}
