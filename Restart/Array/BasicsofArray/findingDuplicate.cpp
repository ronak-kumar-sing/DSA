#include <iostream>
#include <unordered_map>
using namespace std;
// * Using Brute Force
// ! O(n^2)
int BruteForce(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    for (int j = 1; j < n; j++)
    {
      if (arr[i] == arr[j])
      {
        return arr[i];
      }
    }
  }
  return -1;
}

// * Using hashing
// ! O(2n) but Space complexcity O(k) k-> largest No in array
// ! alway give's the smallest duplicate no not which come first in array

int Hashing(int arr[], int n)
{
  int hash[10] = {0};
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }
  for (int i = 0; i < n; i++)
  {
    if (hash[i] > 1)
    {
      return i;
    }
  }
  return -1;
}

//* Using Unordered map
//* TC : O(n) SP: O(k) k -> Unique element

int Unordered(int arr[], int n)
{
  unordered_map<int, int> mapp;
  for (int i = 0; i < n; i++)
  {
    mapp[arr[i]]++;
  }
  for (auto i : mapp)
  {
    if (i.second > 1)
      return i.first;
  }
  return -1;
}

int main()
{
  int n;
  cin >> n;
  int arr[10];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << Unordered(arr, n);
  return 0;
}