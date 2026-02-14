/*
  ========================================================================
                        BUBBLE SORT ALGORITHM
  ========================================================================

  WHAT IS BUBBLE SORT?
  - It's a simple sorting algorithm that repeatedly steps through the list
  - Compares adjacent elements and swaps them if they're in wrong order
  - Continues until the entire array is sorted
  - Called "bubble" because larger elements "bubble up" to the end

  HOW IT WORKS:
  1. Compare each pair of adjacent elements (arr[j-1], arr[j])
  2. If left element > right element, swap them
  3. After each pass, the largest unsorted element moves to its correct position
  4. In next pass, we reduce the range by 1 (we know last element is sorted)
  5. Repeat until array is sorted

  EXAMPLE: [13, 46, 24, 52, 20, 9]
  Pass 1: 13,46 | 24,46 | 24,52 | 20,52 | 9,52  → [13, 24, 20, 9, 46, 52]
  Pass 2: 13,24 | 13,20 | 9,20 | (52 done)      → [13, 9, 20, 24, 46, 52]
  ...and so on until sorted

  TIME COMPLEXITY:
  - Best case:    O(n)   [Already sorted array + optimization flag]
  - Average case: O(n²)  [Random order]
  - Worst case:   O(n²)  [Reverse sorted array]

  SPACE COMPLEXITY: O(1) [Sorts in-place, no extra space needed]

  WHEN TO USE:
  ✓ Small datasets (n < 50)
  ✓ Nearly sorted data
  ✓ Teaching/learning sorting concepts
  ✗ Large datasets (use QuickSort, MergeSort instead)
  ✗ Performance-critical applications

  ADVANTAGES:
  + Simple to understand and implement
  + Stable sort (equal elements maintain relative order)
  + In-place sorting (no extra memory)
  + Can detect already sorted arrays (with optimization)

  DISADVANTAGES:
  - Very slow for large datasets O(n²)
  - Many unnecessary comparisons
  - Not practical for real-world applications

  INTERVIEW EXPLANATION:
  "Bubble sort works by comparing adjacent pairs and swapping if needed.
   Each pass moves the largest element to its final position. Time complexity
   is O(n²) making it inefficient for large data, but great for learning and
   small datasets. It's stable and sorts in-place with O(1) space."
  ========================================================================
*/

#include <iostream>
using namespace std;

/*
  UTILITY FUNCTION: Print array
  - Displays all elements separated by space
  - Helps verify if sorting worked correctly
*/
void print_arr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

/*
  BUBBLE SORT FUNCTION
  Parameters: arr[] = array to sort, n = size of array

  Algorithm explanation:
  - Outer loop (i): Controls number of passes (0 to n-1)
  - Inner loop (j): Compares adjacent elements (1 to n-i)

  Why (n-i)?
    After each pass, the last i elements are sorted and in correct position.
    We don't need to compare them again in next passes.
    Example: After pass 1, last element is sorted. After pass 2, last 2 are sorted.
    This optimization reduces comparisons from n² to approximately n²/2.

  Swap logic:
    if (arr[j-1] > arr[j]) → If left element is greater than right
      swap(arr[j-1], arr[j]) → Exchange their positions
*/
void bubble_sort(int arr[], int n)
{
  // Outer loop: Each iteration is one complete pass through the array
  for (int i = 0; i < n; i++)
  {
    // Inner loop: Compare adjacent pairs and bubble largest element to end
    // Range reduces: (n-1), (n-2), (n-3)... because last i elements are sorted
    for (int j = 1; j < n - i; j++)
    {
      // If current element is bigger than previous, swap them
      if (arr[j - 1] > arr[j])
      {
        swap(arr[j - 1], arr[j]);
      }
    }
    // After this pass, the 'i-th' largest element is at correct position
  }
  // Array is now sorted in ascending order
}

/*
  MAIN FUNCTION: Test bubble sort with test cases
*/
int main()
{
  // Test case 1: Random array
  int arr[] = {13, 46, 24, 52, 20, 9};

  // Test case 2: Reverse sorted array (worst case for bubble sort)
  int arr1[] = {5, 4, 3, 2, 1};

  // Call bubble sort on both arrays
  bubble_sort(arr, 6);
  bubble_sort(arr1, 5);

  // Print results
  cout << "Sorted array 1: ";
  print_arr(arr, 6); // Expected: 9 13 20 24 46 52

  cout << "Sorted array 2: ";
  print_arr(arr1, 5); // Expected: 1 2 3 4 5

  return 0;
}