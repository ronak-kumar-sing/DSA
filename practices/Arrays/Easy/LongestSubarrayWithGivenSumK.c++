#include <iostream>
#include <vector>
#include <map>
using namespace std;

// * Brute Force
// TC : O(n^2)
// SC : O(1)
vector<int> subArray(int arr[], int n, int k)
{
  pair<int, int> p = {-1, -1};
  int maxLength = 0;

  for (int i = 0; i < n; i++)
  {
    int Sum = 0;
    for (int j = i; j < n; j++)
    {
      Sum += arr[j];
      if (Sum == k)
      {
        int currentLength = j - i + 1;
        if (maxLength < currentLength)
        {
          maxLength = currentLength;
          p = {i, j};
        }
      }
      else if (Sum > k)
      {
        break;
      }
    }
  }
  return {p.first, p.second};
}

// * Using Hashing
// TC : O(n)
// SC : O(n)
vector<int> usingHash(int arr[], int n, int k)
{
  map<int, int> mpp;
  int maxLen = 0;
  int sum = 0;
  int startIdx = -1, endIdx = -1;

  for (int i = 0; i < n; i++)
  {
    sum += arr[i];

    if (sum == k)
    {
      if (maxLen < i + 1)
      {
        maxLen = i + 1;
        startIdx = 0;
        endIdx = i;
      }
    }

    int rem = sum - k;
    if (mpp.find(rem) != mpp.end())
    {
      int len = i - mpp[rem];
      if (maxLen < len)
      {
        maxLen = len;
        startIdx = mpp[rem] + 1;
        endIdx = i;
      }
    }

    if (mpp.find(sum) == mpp.end())
    {
      mpp[sum] = i;
    }
  }

  return {startIdx, endIdx};
}

// * Optimal Sol only for Positive and 0's (Two Pointer/Slidding Window)
// TC : O(2n)
// SC : O(1)
vector<int> Optimal(int arr[], int n, int k)
{
  int left = 0, right = 0;
  int sum = 0;
  int maxLen = 0;
  int startIdx = -1, endIdx = -1;

  while (right < n)
  {
    sum += arr[right];

    while (sum > k && left <= right)
    {
      sum -= arr[left];
      left++;
    }

    if (sum == k)
    {
      int currentLen = right - left + 1;
      if (currentLen > maxLen)
      {
        maxLen = currentLen;
        startIdx = left;
        endIdx = right;
      }
    }

    right++;
  }

  return {startIdx, endIdx};
}

void runTestCase(int testNum, int arr[], int n, int k, string method = "Brute Force")
{
  cout << "\n--- Test Case " << testNum << " (" << method << ") ---" << endl;
  cout << "Array: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << "\nTarget Sum: " << k << endl;

  vector<int> result;
  if (method == "Brute Force")
    result = subArray(arr, n, k);
  else if (method == "Hashing")
    result = usingHash(arr, n, k);
  else if (method == "Optimal")
    result = Optimal(arr, n, k);

  if (result[0] == -1)
  {
    cout << "No subarray found with sum " << k << endl;
  }
  else
  {
    int length = result[1] - result[0] + 1;
    cout << "Longest subarray found at indices [" << result[0] << ", " << result[1]
         << "] with length " << length << endl;
    cout << "Elements: ";
    for (int i = result[0]; i <= result[1]; i++)
    {
      cout << arr[i];
      if (i < result[1])
        cout << " + ";
    }
    cout << " = " << k << endl;
  }
}

int main()
{
  cout << "=== COMPARING ALL THREE METHODS ===" << endl;

  // Test Case 1: Your specific test case
  int arr1[] = {1, 2, 2, 1, 1, 1, 1, 2};
  cout << "\n>> Test with array {1, 2, 2, 1, 1, 1, 1, 2} and k=4:" << endl;
  runTestCase(1, arr1, 8, 4, "Brute Force");
  runTestCase(1, arr1, 8, 4, "Hashing");
  runTestCase(1, arr1, 8, 4, "Optimal");

  // Test Case 2: Multiple consecutive 1's
  int arr2[] = {1, 1, 1, 1, 1, 1};
  cout << "\n>> Test with array {1, 1, 1, 1, 1, 1} and k=3:" << endl;
  runTestCase(2, arr2, 6, 3, "Brute Force");
  runTestCase(2, arr2, 6, 3, "Hashing");
  runTestCase(2, arr2, 6, 3, "Optimal");

  // Test Case 3: Normal case
  int arr3[] = {1, 2, 3, 4, 5};
  cout << "\n>> Test with array {1, 2, 3, 4, 5} and k=9:" << endl;
  runTestCase(3, arr3, 5, 9, "Brute Force");
  runTestCase(3, arr3, 5, 9, "Hashing");
  runTestCase(3, arr3, 5, 9, "Optimal");

  // Test Case 4: Single element
  int arr4[] = {5};
  cout << "\n>> Test with array {5} and k=5:" << endl;
  runTestCase(4, arr4, 1, 5, "Brute Force");
  runTestCase(4, arr4, 1, 5, "Hashing");
  runTestCase(4, arr4, 1, 5, "Optimal");

  // Test Case 5: No solution
  int arr5[] = {1, 2, 3, 4};
  cout << "\n>> Test with array {1, 2, 3, 4} and k=15:" << endl;
  runTestCase(5, arr5, 4, 15, "Brute Force");
  runTestCase(5, arr5, 4, 15, "Hashing");
  runTestCase(5, arr5, 4, 15, "Optimal");

  return 0;
}
