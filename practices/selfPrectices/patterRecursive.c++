#include <iostream>
using namespace std;

void patterNormal(int row, int col)
{
  if (row == 0)
  {
    return;
  }
  if (row > col)
  {
    patterNormal(row, col + 1);
    cout << "* ";
  }
  else
  {
    patterNormal(row - 1, 0);
    cout << "\n";
  }
}

void patterR(int row, int col)
{
  if (row == 0)
  {
    return;
  }
  if (row > col)
  {
    cout << "* ";
    patterR(row, col + 1);
  }
  else
  {
    cout << "\n";
    patterR(row - 1, 0);
  }
}

int main()
{
  int n;
  cin >> n;
  patterNormal(n, 0);

  return 0;
}