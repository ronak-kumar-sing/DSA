#include <iostream>
using namespace std;

//* Brute froce
//  Time Complexity: O(N2)
// Space Complexity: O(1)
int BruteFindMissing(int arr[], int n)
{
  for (int i = 1; i <= n; i++)
  {
    int flag = 0;
    for (int j = 0; j < n; j++)
    {
      if (arr[j] == i)
      {
        flag = 1;
        break;
      }
    }
    if (flag == 0)
      return i;
  }
  return -1;
}

// * Better Approach
// Time Complexity: O(N) + O(N) ~ O(2*N)
// Space Complexity: O(N)
int BetterFindMissing(int arr[], int n)
{
  int hash[n + 2]; // the hash[0] should always 0;

  for (int i = 0; i < n + 2; i++)
  {
    hash[i] = 0;
  }
  // storing the frequencies:
  for (int i = 0; i < n; i++)
  {
    if (arr[i] >= 0 && arr[i] <= n + 1) // * Bound Check
      hash[arr[i]]++;
  }
  for (int i = 1; i < n + 1; i++)
  {
    if (hash[i] == 0)
      return i;
  }
  return -1;
}

// * Optimal_1 (Using Sum) not For Long(sum = N(N+1) / 2;
int sumFindMissing(int arr[], int n)
{
  int sum1 = (n + 1) * (n + 2) / 2;
  int sum2 = 0;
  for (int i = 0; i < n; i++)
  {
    sum2 += arr[i];
  }
  int result = sum1 - sum2;
  return result;
}

//* Optimal_2 (Using XOR)
int xorFindMissing(int arr[], int n)
{
  int Xor1 = 0;
  int Xor2 = 0;
  for (int i = 0; i < n; i++)
  {
    Xor2 = Xor2 ^ arr[i];
    Xor1 = Xor1 ^ (i + 1);
  }
  Xor1 = Xor1 ^ n + 1;
  int result = Xor1 ^ Xor2;
  return result;
}

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  // cout << "Missing number is :" << BruteFindMissing(arr, n);
  // cout << "Missing number is :" << BetterFindMissing(arr, n);
  // cout << "Missing number is :" << sumFindMissing(arr, n);
  cout << "Missing number is :" << xorFindMissing(arr, n);

  return 0;
}