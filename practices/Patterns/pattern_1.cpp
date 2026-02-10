#include <iostream>
using namespace std;

// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P1.png
// * * * *
// * * * *
// * * * *
// * * * *

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < n; j++)
      cout << "* ";
    cout << '\n';
  }
  return 0;
}