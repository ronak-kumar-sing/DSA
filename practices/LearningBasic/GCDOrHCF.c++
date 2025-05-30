#include <iostream>
// #include <math.h>
using namespace std;
// * brute Froce
// int GreaterDivser(int n1, int n2)
// {
//   int value;
//   for (int i = min(n1, n2); i >= 1; i++)
//   {
//     if (n1 % i == 0 && n2 % i == 0)
//     {
//       value = i;
//       break;
//     }
//   }
//   return value;
// }
// * better
int GreaterDivser(int a, int b)
{
  int value;
  while (a > 0 && b > 0)
  {
    if (a > b)
      a %= b;
    else
    {
      b %= a;
    }
  }
  if (a == 0)
    value = b;
  else
    value = a;
  return value;
}

int main()
{
  int n1, n2;
  cin >> n1 >> n2;
  int gcd = GreaterDivser(n1, n2);
  cout << gcd;
  return 0;
}