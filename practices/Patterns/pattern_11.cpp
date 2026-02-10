#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P11.png

// 0
// 1 0
// 0 1 0
// 1 0 1 0
// 0 1 0 1 0
// 1 0 1 0 1 0

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << ((i + j) % 2) << " ";
    }
    cout << '\n';
  }
  return 0;
}