#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P5.png

// *
// * *
// * * *
// * * * *

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = n; j >= i; j--)
    {
      cout << "* ";
    }
    cout << '\n';
  }
  return 0;
}