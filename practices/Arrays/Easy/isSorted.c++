#include <iostream>
using namespace std;

bool check(int nums[], int n)
{
  int count = 0;
  for (int i = 0; i < n - 1; i++)
  {
    if (nums[i] > nums[(i + 1)])
      count++;
  }

  return count == 0;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  if (check(arr, n))
    cout << "Array is sorted";
  else
    cout << "Not Sorted";

  return 0;
}