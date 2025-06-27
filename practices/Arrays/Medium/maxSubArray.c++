#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//* Brute Code

vector<int> MaxSubArray(int arr[], int n)
{

  int max = INT_MIN;
  int firstIdx = -1, secondIdx = -1;
  for (int i = 0; i < n; i++)
  {
    int sum = 0;
    for (int j = i; j < n; j++)
    {
      sum += arr[j];
      if (sum > max)
      {
        max = sum;
        firstIdx = i;
        secondIdx = j;
      }
    }
  }
  return {firstIdx, secondIdx};
}

vector<int> KadaneAlo(int arr[], int n)
{
  int max = INT_MIN;
  int firstIdx = -1, secondIdx = -1;
  int sum = 0;
  int temp = 0;
  for (int i = 0; i < n; i++)
  {
    sum += arr[i];

    if (sum > max)
    {
      max = sum;
      firstIdx = temp;
      secondIdx = i;
    }

    if (sum < 0)
    {
      sum = 0;
      temp = i + 1;
    }
  }
  return {firstIdx, secondIdx};
}

int main()
{
  // Test case 1
  cout << "Test Case 1:" << endl;
  int arr1[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int n1 = sizeof(arr1) / sizeof(arr1[0]);

  cout << "Array: ";
  for (int i = 0; i < n1; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;

  vector<int> result1 = MaxSubArray(arr1, n1);
  int start1 = result1[0];
  int end1 = result1[1];

  cout << "Maximum subarray is from index " << start1 << " to " << end1 << endl;
  cout << "Subarray elements: ";
  for (int i = start1; i <= end1; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;

  int maxSum1 = 0;
  for (int i = start1; i <= end1; i++)
  {
    maxSum1 += arr1[i];
  }
  cout << "Maximum sum: " << maxSum1 << endl
       << endl;

  // Test case 2 - All negative numbers
  cout << "Test Case 2 (All negative):" << endl;
  int arr2[] = {-5, -2, -8, -1, -4};
  int n2 = sizeof(arr2) / sizeof(arr2[0]);

  cout << "Array: ";
  for (int i = 0; i < n2; i++)
  {
    cout << arr2[i] << " ";
  }
  cout << endl;

  vector<int> result2 = MaxSubArray(arr2, n2);
  int start2 = result2[0];
  int end2 = result2[1];

  cout << "Maximum subarray is from index " << start2 << " to " << end2 << endl;
  cout << "Subarray elements: ";
  for (int i = start2; i <= end2; i++)
  {
    cout << arr2[i] << " ";
  }
  cout << endl;

  int maxSum2 = 0;
  for (int i = start2; i <= end2; i++)
  {
    maxSum2 += arr2[i];
  }
  cout << "Maximum sum: " << maxSum2 << endl
       << endl;

  // Test case 3 - All positive numbers
  cout << "Test Case 3 (All positive):" << endl;
  int arr3[] = {1, 2, 3, 4, 5};
  int n3 = sizeof(arr3) / sizeof(arr3[0]);

  cout << "Array: ";
  for (int i = 0; i < n3; i++)
  {
    cout << arr3[i] << " ";
  }
  cout << endl;

  vector<int> result3 = MaxSubArray(arr3, n3);
  int start3 = result3[0];
  int end3 = result3[1];

  cout << "Maximum subarray is from index " << start3 << " to " << end3 << endl;
  cout << "Subarray elements: ";
  for (int i = start3; i <= end3; i++)
  {
    cout << arr3[i] << " ";
  }
  cout << endl;

  int maxSum3 = 0;
  for (int i = start3; i <= end3; i++)
  {
    maxSum3 += arr3[i];
  }
  cout << "Maximum sum: " << maxSum3 << endl
       << endl;

  // Test case 4 - Single element
  cout << "Test Case 4 (Single element):" << endl;
  int arr4[] = {5};
  int n4 = sizeof(arr4) / sizeof(arr4[0]);

  cout << "Array: ";
  for (int i = 0; i < n4; i++)
  {
    cout << arr4[i] << " ";
  }
  cout << endl;

  vector<int> result4 = MaxSubArray(arr4, n4);
  int start4 = result4[0];
  int end4 = result4[1];

  cout << "Maximum subarray is from index " << start4 << " to " << end4 << endl;
  cout << "Subarray elements: ";
  for (int i = start4; i <= end4; i++)
  {
    cout << arr4[i] << " ";
  }
  cout << endl;

  int maxSum4 = 0;
  for (int i = start4; i <= end4; i++)
  {
    maxSum4 += arr4[i];
  }
  cout << "Maximum sum: " << maxSum4 << endl;

  // Testing Kadane's Algorithm
  cout << "\n=== Testing Kadane's Algorithm ===" << endl;

  // Test case 1 with Kadane
  cout << "Test Case 1 (Kadane):" << endl;
  cout << "Array: ";
  for (int i = 0; i < n1; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;

  vector<int> kadaneResult1 = KadaneAlo(arr1, n1);
  int kadaneStart1 = kadaneResult1[0];
  int kadaneEnd1 = kadaneResult1[1];

  cout << "Maximum subarray is from index " << kadaneStart1 << " to " << kadaneEnd1 << endl;
  cout << "Subarray elements: ";
  for (int i = kadaneStart1; i <= kadaneEnd1; i++)
  {
    cout << arr1[i] << " ";
  }
  cout << endl;

  int kadaneMaxSum1 = 0;
  for (int i = kadaneStart1; i <= kadaneEnd1; i++)
  {
    kadaneMaxSum1 += arr1[i];
  }
  cout << "Maximum sum: " << kadaneMaxSum1 << endl;

  return 0;
}