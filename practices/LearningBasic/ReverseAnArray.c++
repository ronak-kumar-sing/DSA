#include <iostream>
using namespace std;

void reverse(int arr[], int n, int i)
{
  // Base case: stop when we reach or pass the middle
  if (i >= n / 2)
    return;

  // Swap elements from both ends
  swap(arr[i], arr[n - i - 1]);

  // Recursive call with next index
  reverse(arr, n, i + 1);
}

int main()
{
  int n;
  cout << "Enter number of elements: ";
  cin >> n;

  int arr[100];
  cout << "Enter " << n << " elements: ";
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Original array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  reverse(arr, n, 0);

  cout << "Reversed array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  return 0;
}