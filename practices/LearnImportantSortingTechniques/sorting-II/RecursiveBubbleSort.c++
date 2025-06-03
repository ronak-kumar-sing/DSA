#include <iostream>
using namespace std;

/**
 * RECURSIVE BUBBLE SORT - Easy to Understand Version
 *
 * How Bubble Sort Works:
 * 1. Compare adjacent elements and swap if they're in wrong order
 * 2. After each complete pass, the largest element "bubbles up" to the end
 * 3. Repeat for remaining elements (excluding the already sorted ones)
 */

/**
 * @param arr: The array to sort
 * @param n: Number of elements left to sort (reduces with each pass)
 * @param i: Current position we're comparing (starts from 0 each pass)
 */
void rBubbleSort(int arr[], int n, int i)
{
  // BASE CASE: If no elements left to sort, we're done!
  if (n == 0)
  {
    return;
  }

  // If we haven't finished current pass
  if (i < n)
  {
    // Compare adjacent elements and swap if needed
    if (arr[i] > arr[i + 1])
    {
      swap(arr[i], arr[i + 1]);
      cout << "Swapped " << arr[i + 1] << " and " << arr[i] << endl;
    }

    // Move to next pair in current pass
    rBubbleSort(arr, n, i + 1);
  }
  else
  {
    // Current pass complete! Start new pass with one less element
    cout << "Pass completed. Array now: ";
    for (int k = 0; k <= n; k++)
      cout << arr[k] << " ";
    cout << endl;

    rBubbleSort(arr, n - 1, 0);
  }
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
  cout << "\n\nSorting Process:\n";

  // Start sorting with (n-1) comparisons needed in first pass
  rBubbleSort(arr, n - 1, 0);

  cout << "\nFinal Sorted Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}