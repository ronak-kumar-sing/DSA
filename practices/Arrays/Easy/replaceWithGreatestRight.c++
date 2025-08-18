/*
Problem: Replace Elements with Greatest Element on Right Side

Description:
Given an array arr, replace every element in that array with the greatest element
among the elements to its right, and replace the last element with -1.

After doing so, return the array.

Example 1:
Input: arr = [17,18,5,4,6,1]
Output: [18,6,6,6,1,-1]
Explanation:
- index 0 --> the greatest element to the right of index 0 is index 1 (18).
- index 1 --> the greatest element to the right of index 1 is index 4 (6).
- index 2 --> the greatest element to the right of index 2 is index 4 (6).
- index 3 --> the greatest element to the right of index 3 is index 4 (6).
- index 4 --> the greatest element to the right of index 4 is index 5 (1).
- index 5 --> there are no elements to the right of index 5, so we put -1.

Example 2:
Input: arr = [400]
Output: [-1]
Explanation: There are no elements to the right of index 0.

Constraints:
- 1 <= arr.length <= 10^4
- 1 <= arr[i] <= 10^5

Time Complexity: O(n)
Space Complexity: O(1)
*/

#include <iostream>
#include <vector>
#include <cassert>
using namespace std;
// Brute Force
// class Solution
// {
// public:
//   vector<int> replaceElements(vector<int> &arr)
//   {
//     vector<int> ans;
//     for (int i = 0; i < arr.size(); i++)
//     {
//       int grt = -1;
//       for (int j = i + 1; j < arr.size(); j++)
//       {
//         grt = max(grt, arr[j]);
//       }
//       ans.push_back(grt);
//     }
//     return ans;
//   }
// };

// Suffix Max
class Solution
{
public:
  vector<int> replaceElements(vector<int> &arr)
  {
    int n = arr.size();
    vector<int> ans(n);
    int rightMax = -1;
    for (int i = n - 1; i >= 0; i--)
    {
      ans[i] = rightMax;
      rightMax = max(rightMax, arr[i]);
    }
    return ans;
  }
};

// Test cases
void runTests()
{
  Solution sol;

  // Test Case 1
  vector<int> arr1 = {17, 18, 5, 4, 6, 1};
  vector<int> expected1 = {18, 6, 6, 6, 1, -1};
  vector<int> result1 = sol.replaceElements(arr1);
  cout << "Test 1:" << endl;
  cout << "Expected: [";
  for (int i = 0; i < expected1.size(); i++)
  {
    cout << expected1[i];
    if (i < expected1.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Output:   [";
  for (int i = 0; i < result1.size(); i++)
  {
    cout << result1[i];
    if (i < result1.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test Case 2
  vector<int> arr2 = {400};
  vector<int> expected2 = {-1};
  vector<int> result2 = sol.replaceElements(arr2);
  cout << "Test 2:" << endl;
  cout << "Expected: [";
  for (int i = 0; i < expected2.size(); i++)
  {
    cout << expected2[i];
    if (i < expected2.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Output:   [";
  for (int i = 0; i < result2.size(); i++)
  {
    cout << result2[i];
    if (i < result2.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test Case 3: Two elements
  vector<int> arr3 = {1, 2};
  vector<int> expected3 = {2, -1};
  vector<int> result3 = sol.replaceElements(arr3);
  cout << "Test 3:" << endl;
  cout << "Expected: [";
  for (int i = 0; i < expected3.size(); i++)
  {
    cout << expected3[i];
    if (i < expected3.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Output:   [";
  for (int i = 0; i < result3.size(); i++)
  {
    cout << result3[i];
    if (i < result3.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test Case 4: Decreasing array
  vector<int> arr4 = {5, 4, 3, 2, 1};
  vector<int> expected4 = {4, 3, 2, 1, -1};
  vector<int> result4 = sol.replaceElements(arr4);
  cout << "Test 4:" << endl;
  cout << "Expected: [";
  for (int i = 0; i < expected4.size(); i++)
  {
    cout << expected4[i];
    if (i < expected4.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Output:   [";
  for (int i = 0; i < result4.size(); i++)
  {
    cout << result4[i];
    if (i < result4.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;

  // Test Case 5: All same elements
  vector<int> arr5 = {3, 3, 3, 3};
  vector<int> expected5 = {3, 3, 3, -1};
  vector<int> result5 = sol.replaceElements(arr5);
  cout << "Test 5:" << endl;
  cout << "Expected: [";
  for (int i = 0; i < expected5.size(); i++)
  {
    cout << expected5[i];
    if (i < expected5.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl;
  cout << "Output:   [";
  for (int i = 0; i < result5.size(); i++)
  {
    cout << result5[i];
    if (i < result5.size() - 1)
      cout << ", ";
  }
  cout << "]" << endl
       << endl;
}

int main()
{
  runTests();
  return 0;
}
