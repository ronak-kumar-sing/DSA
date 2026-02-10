#include <iostream>
using namespace std;
// ? pattern image url :- https://static.takeuforward.org/wp/uploads/2022/08/P10.png

//*
//* *
//* * *
//* * * *
//* * *
//* *
//*

int main()
{
  int n;
  cin >> n;
  for (int i = 0; i < 2 * n; i++)
  {
    int star = i <= n ? i : 2 * n - i;
    for (int j = 1; j < star; j++)
    {
      cout << "* ";
    }
    cout << '\n';
  }
  return 0;
}