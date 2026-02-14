/*
  ========================================================================
                     INSERTION SORT ALGORITHM
  ========================================================================

  WHAT IS INSERTION SORT?
  - It's a sorting algorithm that builds the sorted array one item at a time
  - Divides array into sorted and unsorted portions
  - Picks elements from unsorted part and inserts them into sorted part
  - Works like sorting playing cards in your hand

  HOW IT WORKS:
  1. Assume first element is already sorted (part of sorted portion)
  2. For each next element, find its correct position in sorted portion
  3. Shift all larger elements one position to the right
  4. Insert the element at found position
  5. Repeat until all elements are processed

  EXAMPLE: [13, 46, 24, 52, 20, 9]
  Start:    [13] | 46, 24, 52, 20, 9 (13 is sorted)
  Step 1:   [13, 46] | 24, 52, 20, 9 (46 > 13, no shift needed)
  Step 2:   [13, 24, 46] | 52, 20, 9 (24 < 46, shift 46. 24 > 13, insert after)
  Step 3:   [13, 24, 46, 52] | 20, 9 (52 > 46, no shift needed)
  Step 4:   [13, 20, 24, 46, 52] | 9 (20 < 46,24, shift. Compare with 13)
  Step 5:   [9, 13, 20, 24, 46, 52] (9 is smallest, all shifted)

  TIME COMPLEXITY:
  - Best case:    O(n)   [Already sorted array - only comparisons, no shifts]
  - Average case: O(n²)  [Random order]
  - Worst case:   O(n²)  [Reverse sorted array - every element needs shifting]

  SPACE COMPLEXITY: O(1) [Sorts in-place, no extra data structure needed]

  WHEN TO USE:
  ✓ Small to medium datasets (n < 100)
  ✓ Nearly sorted data (performs best here, close to O(n))
  ✓ Online sorting (can sort data as it arrives)
  ✓ Stable sort required
  ✗ Large datasets (use QuickSort, MergeSort instead)

  ADVANTAGES:
  + Simple, intuitive algorithm
  + Stable sort (maintain relative order of equal elements)
  + In-place sorting (no extra memory)
  + Efficient for small datasets
  + Adaptive: great for nearly sorted data (O(n))
  + Online: can sort while receiving new elements

  DISADVANTAGES:
  - O(n²) for random/reverse sorted data
  - Many shifting operations (slower than bubble sort in worst case)
  - Not practical for large-scale data

  KEY DIFFERENCES FROM BUBBLE SORT:
  Bubble Sort:     Compares adjacent pairs, swaps many times
  Insertion Sort:  Finds correct position, then inserts (fewer swaps)
  Result: Insertion sort is generally faster than bubble sort!

  INTERVIEW EXPLANATION:
  "Insertion sort builds a sorted array one element at a time, like sorting
   playing cards. For each new element, I find its correct position in the
   sorted portion by comparing, then shift larger elements right and insert it.
   Time is O(n²) for random data but O(n) for nearly sorted data. It's stable,
   in-place, and works well for small datasets and online sorting scenarios."
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
  INSERTION SORT FUNCTION
  Parameters: arr[] = array to sort, n = size of array

  Algorithm explanation:
  - Outer loop (i): Iterates from position 1 to n-1
    Why start from 1? Because first element (index 0) is considered pre-sorted

  - For each element at position i:
    1. Store it in j (current position)
    2. Compare arr[j] with arr[j-1] (previous element)
    3. If previous is greater, shift it right and move left (j--)
    4. Continue shifting until correct position found
    5. Insert element at position j

  - After each iteration of outer loop, first (i+1) elements are sorted
*/
void insertion_sort(int arr[], int n)
{
  // Outer loop: Start from index 1 (first element is pre-sorted)
  // i represents the element we're inserting into sorted portion
  for (int i = 1; i < n; i++)
  {
    int j = i;

    // Inner loop (while): Find correct position for arr[i]
    // Keep comparing with previous element and shift if needed
    while (j > 0 && arr[j - 1] > arr[j])
    {
      // Current element is smaller than previous, need to shift
      swap(arr[j - 1], arr[j]);
      j--; // Move left to continue comparing
    }
    // When while loop ends, arr[j] is in correct position
    // All elements from 0 to i are now sorted
  }
}

/*
  MAIN FUNCTION: Test insertion sort with test cases
*/
int main()
{
  // Test case 1: Random array
  int arr[] = {13, 46, 24, 52, 20, 9};

  // Test case 2: Reverse sorted array (worst case)
  int arr1[] = {5, 4, 3, 2, 1};

  // Call insertion sort on both arrays
  insertion_sort(arr, 6);
  insertion_sort(arr1, 5);

  // Print results
  cout << "Sorted array 1: ";
  print_arr(arr, 6); // Expected: 9 13 20 24 46 52

  cout << "Sorted array 2: ";
  print_arr(arr1, 5); // Expected: 1 2 3 4 5

  return 0;
}