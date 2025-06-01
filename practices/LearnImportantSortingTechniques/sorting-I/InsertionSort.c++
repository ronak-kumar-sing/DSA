#include <iostream>
using namespace std;

// * Sample Input
// 6
// 7 9 3 9 4 2

// * Example Execution; // Take an element & place it at it's correct Position
// Example Execution : For array [64, 34, 25, 12, 22]

// Pass 1 : [ 34, 64, 25, 12, 22 ]
// Pass 2 : [ 25, 34, 64, 12, 22 ]
// Pass 3 : [ 12, 25, 34, 64, 22 ]
// Pass 4 : [ 12, 22, 25, 34, 64 ]

// Time Complexity : O(n^2)
// Space Complexity : O(1)

void InsertionSort(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
      swap(arr[j - 1], arr[j]);
      j--;
    }
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  InsertionSort(arr, n);

  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}