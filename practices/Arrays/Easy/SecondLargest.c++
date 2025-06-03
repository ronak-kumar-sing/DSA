#include <iostream>
#include <vector>
#include <climits>
using namespace std;

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/**
 * 🎯 FIND SECOND LARGEST ELEMENT - Easy to Understand Version
 *
 * 🧠 Main Idea: Keep track of two variables:
 * - largest: The biggest number we've seen so far
 * - sLargest: The second biggest number we've seen so far
 *
 * 🏠 Real Life Analogy: Finding second tallest person in a group
 * 1. Look at each person one by one
 * 2. If someone is taller than current tallest → they become tallest,
 *    old tallest becomes second tallest
 * 3. If someone is shorter than tallest but taller than second tallest →
 *    they become second tallest
 */

// Sample Input
// 6
// 3 7 1 7 8 2

int findSecondLargest(int n, vector<int> &arr)
{
  if (n < 2)
    return -1;
  int largest = INT_MIN;
  int sLargest = INT_MIN;

  for (int i = 0; i < n; i++)
  {
    if (largest < arr[i])
    {
      sLargest = largest;
      largest = arr[i];
    }
    else if (largest > arr[i] && sLargest < arr[i])
    {
      sLargest = arr[i];
    }
  }
  return sLargest == INT_MIN ? -1 : sLargest;
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  vector<int> arr(n);
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }

  cout << "\nArray: ";
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }

  int result = findSecondLargest(n, arr);

  if (result == -1)
  {
    cout << "\nNo second largest element found!" << endl;
  }
  else
  {
    cout << "\nSecond largest element: " << result << endl;
  }

  return 0;
}