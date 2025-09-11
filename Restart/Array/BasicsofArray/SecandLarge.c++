#include <iostream>
using namespace std;
int main()
{
  int arr[] = {2, 3, 1, 4, 6, 8, 5};
  int first = INT_MIN, sec = INT_MIN;

  for (int i = 0; i < 7; i++)
  {
    if (arr[i] > first)
    {
      sec = first;
      first = arr[i];
    }
    else if (arr[i] > sec && arr[i] < first)
    {
      sec = arr[i];
    }
  }

  cout << sec;
  return 0;
}