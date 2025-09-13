#include <iostream>
#include <algorithm>
using namespace std;

//! TC : O(n x k) SC: O(1);

void BruteFroce(int arr[], int n, int k) //* k -> No of Rotation's
{
  for (int i = 0; i < k; i++)
  {
    int temp = arr[0];
    for (int j = 1; j < n; j++)
    {
      arr[j - 1] = arr[j];
    }
    arr[n - 1] = temp;
  }
}

//* Using different array

//* TC : O(n) SC : O(n)

void useDiffArray(int arr[], int n, int k)
{
  int temp[100];
  k = k % n;
  for (int i = 0; i < n; i++)
  {
    temp[i] = arr[(k + i) % n];
  }
  for (int i = 0; i < n; i++)
  {
    arr[i] = temp[i];
  }
}

//* Using Reversing Algo
//* TC : O(N) SC: O(1);
void useReversal(int arr[], int n, int k)
{
  k = k % n;
  reverse(arr, arr + n);
  reverse(arr, arr + n - k);
  reverse(arr + n - k, arr + k);
}

int main()
{
  int n;
  cin >> n;
  int arr[10];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  int k;
  cin >> k;
  useDiffArray(arr, n, k);
  for (int i = 0; i < n; i++)
    cout
        << arr[i] << ' ';

  return 0;
}