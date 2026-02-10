#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P18.png

// F
// E F
// D E F
// C D E F
// B C D E F
// A B C D E F

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= i; j++)
    {
      cout << char('A' + n - i + j - 1) << ' ';
    }
    cout << '\n';
  }

  return 0;
}