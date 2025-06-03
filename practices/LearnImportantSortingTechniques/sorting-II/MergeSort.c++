#include <iostream>
#include <vector>
using namespace std;

// * MERGE SORT - Divide and Conquer Algorithm
// * Time Complexity: O(n log n) - Best, Average, Worst case
// * Space Complexity: O(n) - Due to temporary array

// * Sample Input:
// 6
// 2 3 9 2 4 3
// * Expected Output: 2 2 3 3 4 9

/**
 * MERGE Function: Combines two sorted subarrays into one sorted array
 * @param arr: The main array
 * @param low: Starting index of first subarray
 * @param mid: Ending index of first subarray (mid+1 starts second subarray)
 * @param high: Ending index of second subarray
 */
void merge(int arr[], int low, int mid, int high)
{
  // Step 1: Create temporary array to store merged result
  vector<int> temp;

  // Step 2: Initialize pointers for both subarrays
  int left = low;      // Pointer for first subarray [low...mid]
  int right = mid + 1; // Pointer for second subarray [mid+1...high]

  // Step 3: Compare elements and merge in sorted order
  while (left <= mid && right <= high)
  {
    if (arr[left] <= arr[right])
    {
      temp.push_back(arr[left]);
      left++;
    }
    else
    {
      temp.push_back(arr[right]);
      right++;
    }
  }

  // Step 4: Add remaining elements from left subarray (if any)
  while (left <= mid)
  {
    temp.push_back(arr[left]);
    left++;
  }

  // Step 5: Add remaining elements from right subarray (if any)
  while (right <= high)
  {
    temp.push_back(arr[right]);
    right++;
  }

  // Step 6: Copy merged elements back to original array
  for (int i = low; i <= high; i++)
  {
    arr[i] = temp[i - low]; // temp[0] goes to arr[low]
  }
}

/**
 * MERGE SORT Function: Recursively divides array and sorts
 * @param arr: The array to be sorted
 * @param low: Starting index
 * @param high: Ending index
 */
void mergeSort(int arr[], int low, int high)
{
  // Base case: If array has 1 or 0 elements, it's already sorted
  if (low >= high)
    return;

  // Step 1: Find middle point to divide array into two halves
  int mid = (low + high) / 2;

  // Step 2: Recursively sort first half
  mergeSort(arr, low, mid);

  // Step 3: Recursively sort second half
  mergeSort(arr, mid + 1, high);

  // Step 4: Merge the two sorted halves
  merge(arr, low, mid, high);
}

/**
 * MAIN Function: Driver code to test merge sort
 */
int main()
{
  // Input: Read array size and elements
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[100]; // Array to store elements (max 100)
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  // Display original array
  cout << "\nOriginal Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  // Sort the array using merge sort
  mergeSort(arr, 0, n - 1);

  // Display sorted array
  cout << "Sorted Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;

  return 0;
}

/*
 * HOW MERGE SORT WORKS:
 *
 * Example: [2, 3, 9, 2, 4, 3]
 *
 * Step 1: Divide
 *         [2, 3, 9, 2, 4, 3]
 *        /                  \
 *   [2, 3, 9]           [2, 4, 3]
 *   /      \            /      \
 * [2, 3]   [9]      [2, 4]   [3]
 * /   \              /   \
 *[2]  [3]          [2]  [4]
 *
 * Step 2: Conquer (Merge back)
 * [2]  [3]  →  [2, 3]
 * [2]  [4]  →  [2, 4]
 * [2, 3] [9]  →  [2, 3, 9]
 * [2, 4] [3]  →  [2, 3, 4]
 * [2, 3, 9] [2, 3, 4]  →  [2, 2, 3, 3, 4, 9]
 *
 * Final Result: [2, 2, 3, 3, 4, 9]
 */