#include <iostream>
#include <map>
#include <vector>
using namespace std;

int BruteForce(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        cnt++;
      }
    }
    if (cnt > n / 2)
      return arr[i];
  }

  return -1;
}

// * Using map
// TC: O(n), SC: O(n)
int usingMap(int arr[], int n)
{
  map<int, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }

  for (auto it : mpp)
  {
    if (it.second > n / 2)
    {
      return it.first;
    }
  }

  return -1;
}
// * Optimal Approach (Moore's Voting Algorithm)
// TC: O(n), SC: O(1)

int mooreVotingAlgo(int arr[], int n)
{
  int el = -1;
  int cnt = 0;

  // Phase 1: Find candidate
  for (int i = 0; i < n; i++)
  {

    if (arr[i] == el)
    {
      cnt++;
    }
    else if (cnt == 0)
    {
      el = arr[i];
      cnt = 1;
    }
    else
      cnt--;
  }

  // Phase 2: Verify candidate
  cnt = 0;

  for (int i = 0; i < n; i++)
  {
    if (arr[i] == el)
      cnt++;
  }

  if (cnt > n / 2)
    return el;

  return -1;
}

void runTestCase(int testNum, int arr[], int n, string method = "All")
{
  cout << "\n--- Test Case " << testNum << " ---" << endl;
  cout << "Input: [";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i];
    if (i < n - 1)
      cout << ", ";
  }
  cout << "] (size: " << n << ")" << endl;

  if (method == "All" || method == "Brute Force")
  {
    int result1 = BruteForce(arr, n);
    cout << "Brute Force: " << (result1 == -1 ? "No majority" : to_string(result1)) << endl;
  }

  if (method == "All" || method == "HashMap")
  {
    int result2 = usingMap(arr, n);
    cout << "HashMap: " << (result2 == -1 ? "No majority" : to_string(result2)) << endl;
  }

  if (method == "All" || method == "Moore's Voting")
  {
    int result3 = mooreVotingAlgo(arr, n);
    cout << "Moore's Voting: " << (result3 == -1 ? "No majority" : to_string(result3)) << endl;
  }
}

int main()
{
  cout << "=== MAJORITY ELEMENT TEST CASES ===" << endl;

  // Test Case 1: Clear majority
  int arr1[] = {3, 2, 3};
  runTestCase(1, arr1, 3);

  // Test Case 2: Another clear majority
  int arr2[] = {2, 2, 1, 1, 1, 2, 2};
  runTestCase(2, arr2, 7);

  // Test Case 3: All same elements
  int arr3[] = {1, 1, 1, 1};
  runTestCase(3, arr3, 4);

  // Test Case 4: No majority element
  int arr4[] = {1, 2, 3, 4};
  runTestCase(4, arr4, 4);

  // Test Case 5: Single element
  int arr5[] = {5};
  runTestCase(5, arr5, 1);

  // Test Case 6: Even split (no majority)
  int arr6[] = {1, 1, 2, 2};
  runTestCase(6, arr6, 4);

  // Test Case 7: Large majority
  int arr7[] = {1, 1, 1, 1, 2, 3};
  runTestCase(7, arr7, 6);

  // Test Case 8: Edge case - exactly half (no majority)
  int arr8[] = {1, 1, 2, 2, 3, 3};
  runTestCase(8, arr8, 6);

  // cout << "\n--- Interactive Input ---" << endl;
  // int n;
  // cout << "Enter array size: ";
  // cin >> n;
  // int *arr = new int[n];
  // cout << "Enter array elements: ";
  // for (int i = 0; i < n; i++)
  //   cin >> arr[i];

  // runTestCase(9, arr, n);

  // delete[] arr;
  return 0;
}