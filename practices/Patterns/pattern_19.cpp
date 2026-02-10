#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P19.png
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *
// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++)
  {
    int star = i < n ? n - i : i - n + 1;
    for (int j = 0; j < star; j++)
    {
      cout << "* ";
    }
    int space = i < n ? 2 * i : 2 * (2 * n - i - 1);
    for (int j = 0; j < space; j++)
    {
      cout << "  ";
    }
    for (int j = 0; j < star; j++)
    {
      cout << "* ";
    }
    cout << '\n';
  }
  return 0;
}