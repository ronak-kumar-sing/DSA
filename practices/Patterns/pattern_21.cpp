#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P21.png

// * * * * * *
// *         *
// *         *
// *         *
// *         *
// * * * * * *

int main()
{

  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= n; j++)
    {
      if (i == 1 || j == 1 || i == n || j == n)
        cout << "* ";
      else
        cout << "  ";
    }
    cout << '\n';
  }
  return 0;
}