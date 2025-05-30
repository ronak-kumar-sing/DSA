#include <iostream>
using namespace std;
int main()
{
  // * comment - This line should not exicut in the program
  int a;                        // * Interager type value which store should be 4 bytes
  long b;                       // * This also take the Interager value but it has Wider Range
  float c;                      // * It store's the number Like "2.3"
  double d = 2.4534;            // * wider form of float
  long long g = 92348293838;    // * store the double value of long
  long double k = 94809.323432; // * store the wider value then double
  cout << "Size of char " << sizeof(char) << " byte(s)" << "\n";
  cout << "Size of int " << sizeof(int) << " byte(s)" << "\n";
  cout << "Size of long " << sizeof(long) << " byte(s)" << "\n";
  cout << "Size of bool " << sizeof(bool) << " byte(s)" << "\n";
  cout << "Size of float " << sizeof(float) << " byte(s)" << "\n";
  cout << "Size of double " << sizeof(double) << " byte(s)" << "\n";
  cout << "Size of long long " << sizeof(g) << " byte(s)" << "\n";
  cout << "Size of long double " << sizeof(k) << " byte(s)" << "\n";

  return 0;
}