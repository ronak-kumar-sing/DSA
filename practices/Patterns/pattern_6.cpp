#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P6.png

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
    for (int j = 1; j <= n - i + 1; j++)
    {
      cout << j << " ";
    }
    cout << '\n';
  }
  return 0;
}