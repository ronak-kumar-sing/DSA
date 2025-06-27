#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// * sample inPut
// 5
// 1 2 3 4 5
// 5
// 3 4 5 6 7
// *
// 6
// 1 2 2 3 3 3
// 5
// 2 2 3 4 4

/*
 * Function to find intersection of two arrays
 * Returns a vector containing common elements
 *
 * Approach 1: Brute Force
 * Time Complexity: O(n*m)
 * Space Complexity: O(1) - excluding result array
 */
vector<int> intersectionBruteForce(vector<int> &arr1, vector<int> &arr2)
{
  vector<int> result;
  vector<bool> used(arr2.size(), false);
  for (int i = 0; i < arr1.size(); i++)
  {
    for (int j = 0; j < arr2.size(); j++)
    {
      if (arr1[i] == arr2[j] && used[j] == false)
      {

        result.push_back(arr1[i]);
        used[j] = true;
        break; // Move to next element in arr1
      }
    }
  }
  return result;
}
/*
 * Function to find intersection of two sorted arrays
 * Using Two Pointer Approach
 *
 * Time Complexity: O(n+m)
 * Space Complexity: O(1) - excluding result array
 */
vector<int> intersectionTwoPointer(vector<int> &arr1, vector<int> &arr2)
{
  vector<int> result;
  int i = 0, j = 0;
  int n = arr1.size(), m = arr2.size();

  while (i < n && j < m)
  {
    if (arr1[i] == arr2[j])
    {
      result.push_back(arr1[i]);
      i++; // Advance both pointers
      j++; // when elements are equal
    }
    else if (arr1[i] < arr2[j]) // arr1[i] is smaller
    {
      i++; // Move to next element in arr1
    }
    else // arr1[i] > arr2[j], arr2[j] is smaller
    {
      j++; // Move to next element in arr2
    }
  }

  return result;
}

/*
 * Helper function to print vector elements
 */
void printVector(const vector<int> &arr)
{
  cout << "[";
  for (int i = 0; i < arr.size(); i++)
  {
    cout << arr[i];
    if (i < arr.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
}

/*
 * Helper function to input array elements
 */
vector<int> inputArray(int size)
{
  vector<int> arr(size);
  cout << "Enter " << size << " elements: ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }
  return arr;
}

int main()
{
  cout << "=== Array Intersection Program ===" << endl;

  // Input first array
  cout << "\nFirst Array:" << endl;
  cout << "Enter size: ";
  int n1;
  cin >> n1;
  vector<int> arr1 = inputArray(n1);

  // Input second array
  cout << "\nSecond Array:" << endl;
  cout << "Enter size: ";
  int n2;
  cin >> n2;
  vector<int> arr2 = inputArray(n2);

  // Display input arrays
  cout << "\nArray 1: ";
  printVector(arr1);
  cout << "Array 2: ";
  printVector(arr2);

  // Test brute force approach
  cout << "\n--- Brute Force Approach ---" << endl;
  vector<int> result1 = intersectionBruteForce(arr1, arr2);
  cout << "Intersection: ";
  printVector(result1);

  // Sort arrays for two pointer approach
  sort(arr1.begin(), arr1.end());
  sort(arr2.begin(), arr2.end());

  cout << "\n--- Two Pointer Approach (on sorted arrays) ---" << endl;
  cout << "Sorted Array 1: ";
  printVector(arr1);
  cout << "Sorted Array 2: ";
  printVector(arr2);

  vector<int> result2 = intersectionTwoPointer(arr1, arr2);
  cout << "Intersection: ";
  printVector(result2);

  return 0;
}

/*
 * Example Test Cases:
 *
 * Test Case 1:
 * Array 1: [1, 2, 2, 1]
 * Array 2: [2, 2]
 * Expected Output: [2, 2] or [2] (depending on if duplicates allowed)
 *
 * Test Case 2:
 * Array 1: [4, 9, 5]
 * Array 2: [9, 4, 9, 8, 4]
 * Expected Output: [4, 9] or [9, 4]
 *
 * Test Case 3:
 * Array 1: [1, 2, 3]
 * Array 2: [4, 5, 6]
 * Expected Output: [] (empty)
 */