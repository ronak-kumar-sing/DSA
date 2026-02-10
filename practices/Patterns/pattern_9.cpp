#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P9.png

//      *
//    * * *
//  * * * * *
//* * * * * * *
//* * * * * * *
//  * * * * *
//    * * *
//      *

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= 2 * n; i++)
  {
    int space = i <= n ? n - i : i - n - 1;
    int star = i <= n ? 2 * i - 1 : 2 * (2 * n + 1 - i) - 1;
    for (int j = 1; j <= space; j++)
    {
      cout << "  ";
    }

    for (int k = 1; k <= star; k++)
    {
      cout << '*' << " ";
    }
    cout << '\n';
  }
  return 0;
}