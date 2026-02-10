#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P20.png
// *                 *
// * *             * *
// * * *         * * *
// * * * *     * * * *
// * * * * * * * * * *
// * * * *     * * * *
// * * *         * * *
// * *             * *
// *                 *

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++)
  {
    int star = i < n ? i : (2 * n - i);
    for (int j = 0; j < star; j++)
    {
      cout << "* ";
    }
    int space = i < n ? 2 * (n - i) : 2 * (i - n);
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