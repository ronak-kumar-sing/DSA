#include <iostream>
#include <vector>
#include <map>
using namespace std;

// * Brute Force Approach
// TC: O(n^2), SC: O(1)
pair<int, int> BruteForce(int arr[], int n, int target)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = i + 1; j < n; j++) // Start j from i+1 to avoid same element
    {
      if (arr[i] + arr[j] == target)
      {
        return {i, j}; // Return immediately when found
      }
    }
  }
  return {-1, -1}; // Return -1, -1 if no pair found
}

// * Hash Map Approach (Optimal)
// TC: O(n), SC: O(n)
pair<int, int> TwoSumHash(int arr[], int n, int target)
{
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    int rem = target - arr[i];
    if (mpp.find(rem) != mpp.end())
    {
      return {mpp[rem], i};
    }
    mpp[arr[i]] = i;
  }
  return {-1, -1};
}

void runTestCase(int testNum, int arr[], int n, int target, string method = "Brute Force")
{
  cout << "\n--- Test Case " << testNum << " (" << method << ") ---" << endl;
  cout << "Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\nTarget: " << target << endl;

  pair<int, int> result;
  if (method == "Brute Force")
    result = BruteForce(arr, n, target);
  else
    result = TwoSumHash(arr, n, target);

  if (result.first == -1)
  {
    cout << "No pair found with sum " << target << endl;
  }
  else
  {
    cout << "Pair found at indices [" << result.first << ", " << result.second << "]" << endl;
    cout << "Elements: " << arr[result.first] << " + " << arr[result.second]
         << " = " << target << endl;
  }
}

int main()
{
  cout << "=== TWO SUM PROBLEM ===" << endl;

  // Test Case 1: Normal case
  int arr1[] = {2, 7, 11, 15};
  runTestCase(1, arr1, 4, 9, "Brute Force");
  runTestCase(1, arr1, 4, 9, "Hash Map");

  // Test Case 2: Multiple pairs possible
  int arr2[] = {3, 2, 4};
  runTestCase(2, arr2, 3, 6, "Brute Force");
  runTestCase(2, arr2, 3, 6, "Hash Map");

  // Test Case 3: Same number twice
  int arr3[] = {3, 3};
  runTestCase(3, arr3, 2, 6, "Brute Force");
  runTestCase(3, arr3, 2, 6, "Hash Map");

  // Test Case 4: No solution
  int arr4[] = {1, 2, 3, 4};
  runTestCase(4, arr4, 4, 10, "Brute Force");
  runTestCase(4, arr4, 4, 10, "Hash Map");

  // Test Case 5: Negative numbers
  int arr5[] = {-1, -2, -3, -4, -5};
  runTestCase(5, arr5, 5, -8, "Brute Force");
  runTestCase(5, arr5, 5, -8, "Hash Map");

  // cout << "\n--- Interactive Input ---" << endl;
  // int n, target;
  // cout << "Enter array size: ";
  // cin >> n;

  // int *arr = new int[n];
  // cout << "Enter array elements: ";
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];

  // cout << "Enter target sum: ";
  // cin >> target;

  // runTestCase(6, arr, n, target, "Brute Force");
  // runTestCase(6, arr, n, target, "Hash Map");

  // delete[] arr;
  return 0;
}