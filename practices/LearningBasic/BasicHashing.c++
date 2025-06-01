#include <iostream>
using namespace std;
//* Sample Input
// 5
// 1 2 1 3 4
// 5
// 1 2 3 4 5

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  // * preStorting
  int hash[100] = {0};
  for (int i = 0; i < n; i++)
  {
    hash[arr[i]]++;
  }

  int m;
  cin >> m;
  int arr1[n];
  for (int i = 0; i < n; i++)
  {

    cin >> arr1[i];
  }

  for (int i = 0; i < n; i++)
  {
    //* Fetching
    cout << hash[arr1[i]] << " ";
  }

  return 0;
}
