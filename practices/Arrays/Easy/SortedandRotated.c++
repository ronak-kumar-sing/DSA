#include <iostream>
using namespace std;

/*
 * Function to check if array is sorted and rotated
 *
 * Logic Explanation:
 * - A sorted array has 0 "breaks" (places where arr[i] > arr[i+1])
 * - A rotated sorted array has exactly 1 "break"
 * - Example: [1,2,3,4,5] has 0 breaks (sorted)
 * - Example: [3,4,5,1,2] has 1 break at position 2 (5>1) (rotated sorted)
 * - Example: [2,1,3,4] has 2 breaks (not sorted/rotated)
 *
 * We use modulo (%) to handle circular comparison (last element with first)
 */
bool check(int nums[], int n)
{
  int count = 0; // Count number of "breaks" or decreasing points

  // Check each element with its next element (circularly)
  for (int i = 0; i < n; i++)
  {
    // Compare current element with next element (circular using %)
    // (i + 1) % n ensures last element is compared with first element
    if (nums[i] > nums[(i + 1) % n])
      count++; // Found a decreasing point
  }

  // Array is sorted and rotated if there's at most 1 break
  // count <= 1 covers both cases:
  // - count == 0: perfectly sorted array
  // - count == 1: sorted but rotated array
  return count <= 1;
}

int main()
{
  cout << "Enter the size of array: ";
  int n;
  cin >> n;

  cout << "Enter " << n << " elements: ";
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  // Check if array is sorted (with possible rotation)
  if (check(arr, n))
    cout << "Array is sorted and rotated" << endl;
  else
    cout << "Array is not sorted and rotated" << endl;

  return 0;
}

/*
 * Example Test Cases:
 *
 * Input: [1, 2, 3, 4, 5] → Output: "Array is sorted and rotated" (0 breaks)
 * Input: [3, 4, 5, 1, 2] → Output: "Array is sorted and rotated" (1 break)
 * Input: [2, 1, 3, 4]    → Output: "Array is not sorted and rotated" (2 breaks)
 * Input: [1, 3, 2]       → Output: "Array is not sorted and rotated" (2 breaks)
 */