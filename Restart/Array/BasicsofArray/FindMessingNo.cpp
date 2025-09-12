#include <iostream>
using namespace std;

int main()
{
  int n;
  cin >> n;
  int arr[10];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  for (int i = 0; i < n + 1; i++)
  {
    if (arr[i] != i + 1)
    {
      cout << i + 1;
      break;
    }
  }

  return 0;
}