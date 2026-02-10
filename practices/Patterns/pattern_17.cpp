#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P17.png
//         A
//       A B A
//     A B C B A
//   A B C D C B A
// A B C D E D C B A

int main()
{
  int n;
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    int space = n - i;
    for (int j = 0; j < space; j++)
    {
      cout << "  ";
    }
    for (int j = 0; j < i; j++)
    {
      cout << char('A' + j) << ' ';
    }
    for (int j = i; j >= 0; j--)
    {
      cout << char('A' + j) << " ";
    }
    cout << '\n';
  }
  return 0;
}