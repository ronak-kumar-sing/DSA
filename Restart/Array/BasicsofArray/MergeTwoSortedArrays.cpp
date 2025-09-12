#include <iostream>
using namespace std;

//* Tow Pointer
void TowPointerMerge(int arr1[], int arr2[], int n, int m)
{
  int i = 0, j = 0;
  int arr[100];
  int k = 0;
  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      arr[k] = arr1[i];
      i++;
    }
    else
    {
      arr[k] = arr2[j];
      j++;
    }
    k++;
  }
  while (i < n)
  {
    arr[k++] = arr[i++];
  }
  while (j < m)
  {
    arr[k++] = arr2[j++];
  }
  for (int i = 0; i < n + m; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[10];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int m;
  cin >> m;
  int arr2[10];
  for (int i = 0; i < m; i++)
    cin >> arr2[i];
  TowPointerMerge(arr, arr2, n, m);
  return 0;
}