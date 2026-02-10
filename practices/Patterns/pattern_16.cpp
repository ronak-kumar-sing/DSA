#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P16.png

// A
// B B
// C C C
// D D D D
// E E E E E

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= i; j++)
    {
      cout << char('A' + i) << ' ';
    }
    cout << '\n';
  }

  return 0;
}