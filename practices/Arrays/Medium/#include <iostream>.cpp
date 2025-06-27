#include <iostream>
#include <vector>
#include <cassert>
#include <cstring>
using namespace std;

// Include the function to test
void RearrageArray(int arr[], int n)
{
  vector<int> neg;
  vector<int> ptv;
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < 0)
    {
      neg.push_back(arr[i]);
    }
    else
    {
      ptv.push_back(arr[i]);
    }
  }
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0)
    {
      arr[i] = ptv[i / 2];
    }
    else
    {
      arr[i] = neg[i / 2];
    }
  }
}

// Helper function to check if array follows alternating pattern
bool isAlternating(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    if (i % 2 == 0 && arr[i] < 0) return false; // Even indices should be positive
    if (i % 2 == 1 && arr[i] >= 0) return false; // Odd indices should be negative
  }
  return true;
}

// Helper function to print array
void printArray(int arr[], int n, const string& label)
{
  cout << label << ": ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
}

void testCase1()
{
  cout << "Test Case 1: Equal positive and negative numbers" << endl;
  int arr[] = {1, -2, 3, -4, 5, -6};
  int n = 6;
  int original[] = {1, -2, 3, -4, 5, -6};
  
  printArray(original, n, "Original");
  RearrageArray(arr, n);
  printArray(arr, n, "Rearranged");
  
  assert(isAlternating(arr, n));
  cout << "✓ Test Case 1 passed\n" << endl;
}

void testCase2()
{
  cout << "Test Case 2: Mixed order" << endl;
  int arr[] = {-1, 2, -3, 4, -5, 6};
  int n = 6;
  int original[] = {-1, 2, -3, 4, -5, 6};
  
  printArray(original, n, "Original");
  RearrageArray(arr, n);
  printArray(arr, n, "Rearranged");
  
  assert(isAlternating(arr, n));
  cout << "✓ Test Case 2 passed\n" << endl;
}

void testCase3()
{
  cout << "Test Case 3: Two elements" << endl;
  int arr[] = {-1, 2};
  int n = 2;
  int original[] = {-1, 2};
  
  printArray(original, n, "Original");
  RearrageArray(arr, n);
  printArray(arr, n, "Rearranged");
  
  assert(isAlternating(arr, n));
  cout << "✓ Test Case 3 passed\n" << endl;
}

void testCase4()
{
  cout << "Test Case 4: Larger array" << endl;
  int arr[] = {1, -2, 3, -4, 5, -6, 7, -8};
  int n = 8;
  int original[] = {1, -2, 3, -4, 5, -6, 7, -8};
  
  printArray(original, n, "Original");
  RearrageArray(arr, n);
  printArray(arr, n, "Rearranged");
  
  assert(isAlternating(arr, n));
  cout << "✓ Test Case 4 passed\n" << endl;
}

void testCase5()
{
  cout << "Test Case 5: All positive first, then negative" << endl;
  int arr[] = {1, 2, 3, 4, -1, -2, -3, -4};
  int n = 8;
  int original[] = {1, 2, 3, 4, -1, -2, -3, -4};
  
  printArray(original, n, "Original");
  RearrageArray(arr, n);
  printArray(arr, n, "Rearranged");
  
  assert(isAlternating(arr, n));
  cout << "✓ Test Case 5 passed\n" << endl;
}

int main()
{
  cout << "Running tests for RearrageArray function...\n" << endl;
  
  testCase1();
  testCase2();
  testCase3();
  testCase4();
  testCase5();
  
  cout << "All tests passed! ✓" << endl;
  
  return 0;
}