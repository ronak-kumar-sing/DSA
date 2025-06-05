#include <iostream>
#include <vector>
using namespace std;

/*
 * Function to remove duplicates from a sorted array in-place
 *
 * Algorithm: Two Pointer Technique
 * - Pointer 'i': tracks the position of last unique element
 * - Pointer 'j': scans through the array to find next unique element
 *
 * Logic:
 * - Start with i=0 (first element is always unique)
 * - Compare arr[i] with arr[j] for j from 1 to n-1
 * - If different, move arr[j] to position i+1 and increment i
 * - Return i+1 (count of unique elements)
 *
 * Example: [1,1,2,2,3,3,4] becomes [1,2,3,4,_,_,_] and returns 4
 */
int removeDuplicates(vector<int> &arr)
{
  // Handle edge case: empty array
  if (arr.size() == 0)
    return 0;

  int i = 0; // Pointer to track last unique element position

  // Scan through array starting from second element
  for (int j = 1; j < arr.size(); j++)
  {
    // If current element is different from last unique element
    if (arr[i] != arr[j])
    {
      // Move unique element to next position
      i++;             // Move to next unique position
      arr[i] = arr[j]; // Place the unique element (no swapping needed)
    }
    // If arr[i] == arr[j], it's a duplicate, so skip it
  }

  return i + 1; // Return count of unique elements
}

/*
 * Helper function to print array elements
 */
void printArray(vector<int> &arr, int length)
{
  cout << "Array: ";
  for (int i = 0; i < length; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}

int main()
{
  cout << "Enter the size of sorted array: ";
  int n;
  cin >> n;

  vector<int> arr(n);
  cout << "Enter " << n << " sorted elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "\nOriginal array: ";
  printArray(arr, n);

  // Remove duplicates and get count of unique elements
  int uniqueCount = removeDuplicates(arr);

  cout << "After removing duplicates: ";
  printArray(arr, uniqueCount);

  cout << "Number of unique elements: " << uniqueCount << endl;

  return 0;
}

/*
 * Example Walkthrough:
 * Input: [1, 1, 2, 2, 3, 3, 4]
 *
 * Initial: i=0, arr=[1,1,2,2,3,3,4]
 * j=1: arr[0]=1, arr[1]=1 → same, skip
 * j=2: arr[0]=1, arr[2]=2 → different, i=1, arr[1]=2 → [1,2,2,2,3,3,4]
 * j=3: arr[1]=2, arr[3]=2 → same, skip
 * j=4: arr[1]=2, arr[4]=3 → different, i=2, arr[2]=3 → [1,2,3,2,3,3,4]
 * j=5: arr[2]=3, arr[5]=3 → same, skip
 * j=6: arr[2]=3, arr[6]=4 → different, i=3, arr[3]=4 → [1,2,3,4,3,3,4]
 *
 * Result: [1,2,3,4,...] with 4 unique elements
 *
 * Time Complexity: O(n) - single pass through array
 * Space Complexity: O(1) - in-place modification
 */
