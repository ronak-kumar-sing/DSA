#include <iostream>
using namespace std;

int main()
{
  // * Store the multi char values in on like "Ronak";
  string a;
  // string b;
  // cin >> a >> b; // * It will take single word or when the space is started new value should started;
  getline(cin, a); // * It will take the full Line as input but not take the other line;

  cout << a;
  return 0;
}