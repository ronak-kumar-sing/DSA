#include <iostream>
using namespace std;

bool BruteFroce(int arr[], int n)
{
  int count = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > arr[i + 1] % n)
      count++;
  }
  return count <= 1;
}

int main()
{
  int n;
  cin >> n;
  int arr[100];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  if (BruteFroce(arr, n))
  {
    cout << "Array is sorted and rotated";
  }
  else
  {
    cout << "Array is not sorted and rotated";
  }
  return 0;
}