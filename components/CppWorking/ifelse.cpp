#include <iostream>
using namespace std;

int main()
{
  // ? Write the programe for user so it Identify the is adult or Not

  int a;
  cin >> a;
  if (a > 18)
  {
    cout << "User is an Adult";
  }
  else if (a == 18)
  {
    cout << "User is becoming Adult";
  }
  else
  {
    cout << "User is user age!";
  }
  // * Note :- The if statement should also excute alone when the else or else if is not define to it //

  return 0;
}