#include <iostream>
using namespace std;

/*
 * Function to move all zeros to the end of array while maintaining
 * the relative order of non-zero elements
 *
 * Algorithm: Two-Pass Approach
 * Pass 1: Move all non-zero elements to the front
 * Pass 2: Fill remaining positions with zeros
 *
 * Example: [0,1,0,3,12] becomes [1,3,12,0,0]
 *
 * Time Complexity: O(n) - two passes through array
 * Space Complexity: O(1) - in-place modification
 */
void moveZerosToEnd(int arr[], int n)
{
  int nonZero = 0; // Pointer to track position for next non-zero element

  // PASS 1: Move all non-zero elements to the front
  // Copy non-zero elements to positions 0, 1, 2, ...
  for (int i = 0; i < n; i++)
  {
    if (arr[i] != 0)
    {
      arr[nonZero] = arr[i]; // Place non-zero element at front
      nonZero++;             // Move to next position for non-zero element
    }
    // If arr[i] is 0, we skip it (don't copy)
  }

  // PASS 2: Fill remaining positions with zeros
  // After copying all non-zero elements, fill rest with 0s
  while (nonZero < n)
  {
    arr[nonZero] = 0; // Fill with zero
    nonZero++;        // Move to next position
  }
}

// * Using Two Pointer Approach
// TC: O(n)
// SC: O(1);
void pointerMoveZerosToEnd(int arr[], int n)
{
  int j = -1, i = 0;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == 0)
    {
      j = i;
      break;
    }
  }
  if (j == -1)
    return;
  for (int i = j + 1; i < n; i++)
  {
    if (arr[i] != 0)
    {
      swap(arr[i], arr[j]);
      j++;
    }
  }
}

/*
 * Helper function to print array elements
 */
void printArray(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
    if (i < n - 1)
      cout << " "; // Add space between elements
  }
  cout << endl;
}

int main()
{
  cout << "Enter the size of array: ";
  int n;
  cin >> n;

  int arr[n];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "\nOriginal array: ";
  printArray(arr, n);

  // Move all zeros to the end
  // moveZerosToEnd(arr, n);
  pointerMoveZerosToEnd(arr, n);

  cout << "After moving zeros to end: ";
  printArray(arr, n);

  return 0;
}

/*
 * Step-by-Step Example:
 * Input: [0, 1, 0, 3, 12]
 *
 * PASS 1 - Moving non-zero elements to front:
 * i=0: arr[0]=0 → skip (zero)
 * i=1: arr[1]=1 → arr[0]=1, nonZero=1 → [1, 1, 0, 3, 12]
 * i=2: arr[2]=0 → skip (zero)
 * i=3: arr[3]=3 → arr[1]=3, nonZero=2 → [1, 3, 0, 3, 12]
 * i=4: arr[4]=12 → arr[2]=12, nonZero=3 → [1, 3, 12, 3, 12]
 *
 * PASS 2 - Filling remaining with zeros:
 * nonZero=3: arr[3]=0 → [1, 3, 12, 0, 12]
 * nonZero=4: arr[4]=0 → [1, 3, 12, 0, 0]
 *
 * Final Result: [1, 3, 12, 0, 0]
 *
 * Alternative Single-Pass Approach (Advanced):
 * Use two pointers - one for non-zero position, one for scanning.
 * When found non-zero, swap with non-zero position pointer.
 */