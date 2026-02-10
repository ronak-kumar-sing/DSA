#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P13.png

int main()
{
  int n;
  cin >> n;
  int count = 1;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << count++ << ' ';
    }
    cout << '\n';
  }
  return 0;
}