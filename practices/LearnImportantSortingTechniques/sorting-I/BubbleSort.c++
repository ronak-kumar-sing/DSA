#include <iostream>
using namespace std;

//*Sample Input
// 5
// 2 5 3 1 3

// * Example Execution; // Push the maxValue at last by Adjusent swaping
// Example Execution : For array [64, 34, 25, 12, 22]

// Pass 1 : [ 34, 25, 12, 22, 64 ]

//  Pass 2 : [ 25, 12, 22, 34, 64 ]

// Pass 3 : [ 12, 22, 25, 34, 64 ]

// Pass 4 : [ 12, 22, 25, 34, 64 ]

// Time Complexity : O(n^2) for best case O(N)
// Space Complexity : O(1)
void bubbleSort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    bool didSwap = false;
    for (int j = 0; j < n - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
        didSwap = true;
      }
    }
    if (!didSwap)
    {
      break;
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

  bubbleSort(arr, n);
  cout << "Sorted Array\n";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  return 0;
}