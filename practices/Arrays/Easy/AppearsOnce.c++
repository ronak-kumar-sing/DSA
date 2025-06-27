#include <iostream>
#include <map>
using namespace std;

int BruteReturn(int arr[], int n)
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
    if (cnt == 1)
    {
      return arr[i];
    }
  }

  return -1;
}

// * Using Hashing( But not for larg and negative numbers)

int hashApproach(int arr[], int n)
{
  int max = 0;
  for (int i = 0; i < n; i++)
  {
    if (max < arr[i])
    {
      max = arr[i];
    }
  }
  int hash[max + 1];
  for (int i = 0; i < max + 1; i++)
    hash[i] = 0;
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (hash[arr[i]] == 1)
      return arr[i];
  }
  return -1;
}

//* Using map<long long, int>

int mapApproach(int arr[], int n)
{
  map<long long, int> mpp;
  for (int i = 0; i < n; i++)
  {
    mpp[arr[i]]++;
  }

  for (auto it : mpp)
  {
    if (it.second == 1)
      return it.first;
  }

  return -1;
}

//* Using XOR

int xorApproch(int arr[], int n)
{
  int XOR = 0;
  for (int i = 0; i < n; i++)
  {
    XOR = XOR ^ arr[i];
  }
  return XOR;
}

void testCase(int arr[], int n, int expected, string testName)
{
  cout << "\n=== " << testName << " ===" << endl;
  cout << "Input: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  cout << "Expected: " << expected << endl;
  cout << "BruteReturn: " << BruteReturn(arr, n) << endl;
  cout << "hashApproach: " << hashApproach(arr, n) << endl;
  cout << "mapApproach: " << mapApproach(arr, n) << endl;
  cout << "xorApproach: " << xorApproch(arr, n) << endl;
}

int main()
{
  // Test Case 1
  int arr1[] = {2, 2, 1, 3, 3};
  testCase(arr1, 5, 1, "Basic Case");

  // Test Case 2
  int arr2[] = {7, 1, 1, 2, 2};
  testCase(arr2, 5, 7, "Unique at Start");

  // Test Case 3
  int arr3[] = {1, 1, 2, 2, 9};
  testCase(arr3, 5, 9, "Unique at End");

  return 0;
}