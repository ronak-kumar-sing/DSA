#include <iostream>
using namespace std;

// * Sample Input
// 6
// 7 9 3 9 4 2

// * Example Execution; // Select Min and swap
// Example Execution : For array [64, 34, 25, 12, 22]

// Pass 1 : [ 12, 34, 25, 64, 22 ]

// Pass 2 : [ 12, 22, 25, 64, 34 ]

// Pass 3 : [ 12, 22, 25, 64, 34 ]

// Pass 4 : [ 12, 22, 25, 34, 64 ]

// Time Complexity : O(n^2) Same for all
// Space Complexity : O(1)
void selectionSort(int arr[], int n)
{
  for (int i = 0; i <= n - 2; i++)
  { // * Last element will always be sorted
    int min = i;
    for (int j = i; j < n; j++)
    {
      if (arr[j] < arr[min])
        min = j;
    }
    swap(arr[min], arr[i]);
  }
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  selectionSort(arr, n);

  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  return 0;
}