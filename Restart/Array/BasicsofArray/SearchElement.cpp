#include <iostream>
using namespace std;
//* if the array is sorted
int BinarySearch(int arr[], int n, int key)
{
  int low = 0;
  int high = n - 1;
  while (low <= high)
  {
    int m = low + (high - low) / 2;
    if (arr[m] == key)
      return m;
    else if (arr[m] > key)
    {
      high = m - 1;
    }
    else
    {
      low = m + 1;
    }
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  int arr[10];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  int key;
  cin >> key;

  key = BinarySearch(arr, n, key);
  cout << key << " Found" << endl;

  return 0;
}