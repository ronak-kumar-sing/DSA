#include <iostream>
using namespace std;

/**
 * RECURSIVE INSERTION SORT - Complete Implementation
 *
 * How Insertion Sort Works:
 * 1. Start from the second element (index 1)
 * 2. Compare it with previous elements and insert it in correct position
 * 3. Repeat for all remaining elements
 * 4. Each element gets "inserted" into the already sorted portion
 */

/**
 * Helper function to insert element at correct position
 * @param arr: The array
 * @param i: Current element's original position
 */
void insertElement(int arr[], int i)
{
  // Base case: if we're at the beginning or element is in correct position
  if (i <= 0 || arr[i - 1] <= arr[i])
    return;

  // Swap with previous element and continue
  swap(arr[i - 1], arr[i]);
  insertElement(arr, i - 1);
}

/**
 * Main recursive insertion sort function
 * @param arr: The array to sort
 * @param n: Number of elements to sort
 * @param i: Current element we're inserting (starts from 1)
 */
void rInsertionSort(int arr[], int n, int i)
{
  // Base case: if we've processed all elements
  if (i >= n)
    return;

  // Insert current element in its correct position
  insertElement(arr, i);

  // Move to next element
  rInsertionSort(arr, n, i + 1);
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

  cout << "\nOriginal Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  rInsertionSort(arr, n, 1); // Start from index 1

  cout << "\nSorted Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}