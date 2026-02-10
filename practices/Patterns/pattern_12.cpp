#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P12.png

// 1                 1
// 1 2             2 1
// 1 2 3         3 2 1
// 1 2 3 4     4 3 2 1
// 1 2 3 4 5 5 4 3 2 1

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {

    for (int j = 1; j <= i; j++)
    {
      cout << j << ' ';
    }
    int space = 2 * n - 2 * i;
    for (int j = 0; j < space; j++)
    {
      cout << "  ";
    }
    for (int j = i; j > 0; j--)
    {
      cout << j << ' ';
    }
    cout << '\n';
  }
  return 0;
}