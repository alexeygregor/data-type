#include <iostream>
#include <string>
using namespace std;

enum note
{
  DO = 1,
  RE = 2,
  MI = 4,
  FA = 8,
  SOL = 16,
  LA = 32,
  SI = 64
};

int play (int notes)
{
  if (notes & DO)  {cout << "#DO " ;}
  if (notes & RE)  {cout << "#RE " ;}
  if (notes & MI)  {cout << "#MI " ;}
  if (notes & FA)  {cout << "#FA " ;}
  if (notes & SOL) {cout << "#SOL ";}
  if (notes & LA)  {cout << "#LA " ;}
  if (notes & SI)  {cout << "#SI " ;}
}

int mask (int notes)
{
  int NOTES = 1;
  if      (notes == 1) {NOTES <<= 0;}
  else if (notes == 2) {NOTES <<= 1;}
  else if (notes == 3) {NOTES <<= 2;}
  else if (notes == 4) {NOTES <<= 3;}
  else if (notes == 5) {NOTES <<= 4;}
  else if (notes == 6) {NOTES <<= 5;}
  else if (notes == 7) {NOTES <<= 6;}
  play(NOTES);
}

int main ()
{
  int co = 1, notes = 0;
  string accord, scope;
  cout << "Enter accord: "; cin >> accord;
  cout << endl;

  while (co <= accord.size())
  {
    for (int i = 0; i < co; ++i)
    {
      notes = accord[i] - '0';
    }
    for (int i = 0; i < scope.size() + 1; ++i)
    {
      if (notes == scope[i] - '0') { notes = 0; break; }
    }
    if (notes) {mask(notes); scope += (notes + '0'); }
    co++;
  }
  cout << endl;
}
