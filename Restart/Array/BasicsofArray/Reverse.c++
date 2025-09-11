#include <iostream>
using namespace std;

void useRecusive(int arr[], int end, int start = 0)
{
  if (start >= end)
    return;
  int temp = arr[start];
  arr[start] = arr[end];
  arr[end] = temp;
  useRecusive(arr, end - 1, start + 1);
}

void useTowPointer(int arr[], int n)
{
  int i = 0, j = n - 1;
  while (i <= j)
  {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    i++;
    j--;
  }
}

void Reverse(int arr[], int n)
{
  for (int i = n; i >= 0; i--)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int len = sizeof(arr) / sizeof(arr[0]);
  cout << "Before :" << endl;
  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\nAfter :" << endl;
  // useTowPointer(arr, len);
  useRecusive(arr, len - 1);

  for (int i = 0; i < len; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}