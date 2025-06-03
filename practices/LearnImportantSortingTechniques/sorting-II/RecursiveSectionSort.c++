#include <iostream>
using namespace std;

// * RECURSIVE SELECTION SORT - Easy to Understand Version
// * Sample Input: 5
//                64 34 25 12 22
// * Expected Output: 12 22 25 34 64

/**
 * 🔍 STEP 1: Find the smallest number in the remaining array
 * Think of this like "scanning" the array to find the minimum
 *
 * @param arr: The array we're looking in
 * @param n: Total size of array
 * @param i: Starting position to look from
 * @return: Position (index) where smallest number is found
 */
int minView(int arr[], int n, int i)
{
  int min = i; // Assume first element is smallest

  // Look at all remaining elements
  for (int j = i + 1; j < n; j++)
  {
    // If we find something smaller, remember its position
    if (arr[j] < arr[min])
      min = j;
  }

  return min; // Return position of smallest element
}

/**
 * 🔄 STEP 2: Put smallest number in correct position and repeat
 * This is like organizing books by height - always put shortest one first
 *
 * @param arr: Array to sort
 * @param n: Size of array
 * @param i: Current position we're filling (starts from 0)
 */
void rSelectionSort(int arr[], int n, int i)
{
  // 🛑 STOP: If we've filled all positions except last one
  if (i >= n - 1)
    return;

  // 🔍 Find where the smallest remaining number is
  int minPosition = minView(arr, n, i);

  // 🔄 Swap: Put smallest number in current position
  swap(arr[i], arr[minPosition]);

  cout << "Step " << i + 1 << ": Put " << arr[i]
       << " in position " << i << " → ";
  for (int k = 0; k < n; k++)
    cout << arr[k] << " ";
  cout << endl;

  // 🚀 Recursive call: Fill next position
  rSelectionSort(arr, n, i + 1);
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[100];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "\n🔢 Original Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\n\n📋 Sorting Process:\n";

  rSelectionSort(arr, n, 0); // Start from position 0

  cout << "\n✅ Final Sorted Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

// 🎯 Goal : Sort from smallest to largest

// 📍 Position 0 : Find smallest in[64, 34, 25, 12, 22]
//    → Found 12 at position 3
//    → Swap : [ 12, 34, 25, 64, 22 ]

// 📍 Position 1 : Find smallest in[34, 25, 64, 22]
//    → Found 22 at position 4
//    → Swap : [ 12, 22, 25, 64, 34 ]

// 📍 Position 2 : Find smallest in[25, 64, 34]
//    → Found 25 at position 2
//    → Swap : [ 12, 22, 25, 64, 34 ]

// 📍 Position 3 : Find smallest in[64, 34]
//    → Found 34 at position 4
//    → Swap : [ 12, 22, 25, 34, 64 ]

// ✅ Done !Array is sorted : [ 12, 22, 25, 34, 64 ]