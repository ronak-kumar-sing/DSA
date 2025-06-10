#include <iostream>
using namespace std;

int BruteForce(int arr[], int n) // Fixed typo: BruteFroce -> BruteForce
{
  int maxNum = -1;
  for (int i = 0; i < n; i++)
  {
    int cnt = 0;
    for (int j = 0; j < n; j++) // Fixed: was i++ instead of j++
    {
      if (arr[i] == arr[j])
      {
        cnt++;
      }
    }
    maxNum = max(maxNum, cnt);
  }
  return maxNum;
}

void runTestCase(int testNum, int arr[], int n)
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

  int result = BruteForce(arr, n);
  cout << "Maximum frequency: " << result << endl;

  if (result > n / 2)
  {
    cout << "Has majority element (appears more than " << n / 2 << " times)" << endl;
  }
  else
  {
    cout << "No majority element" << endl;
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

  cout << "\n--- Interactive Input ---" << endl;
  int n;
  cout << "Enter array size: ";
  cin >> n;
  int *arr = new int[n];
  cout << "Enter array elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  runTestCase(9, arr, n);

  delete[] arr;
  return 0;
}