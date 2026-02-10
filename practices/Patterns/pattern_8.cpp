#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P8.png

//* * * * * * *
//  * * * * *
//    * * *
//      *

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << "  ";
    }
    for (int k = 1; k <= 2 * (n - i) + 1; k++)
    {
      cout << '*' << " ";
    }
    cout << '\n';
  }
  return 0;
}