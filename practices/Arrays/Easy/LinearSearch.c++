#include <iostream>
using namespace std;
int linerSearch(int arr[], int n, int key)
{
  for (int i = 0; i < n; i++)
  {
    if (arr[i] == key)
    {
      return i;
    }
  }
  return -1;
}

int main()
{
  int n, key;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cin >> key;
  cout << "at Index : " << linerSearch(arr, n, key);
  return 0;
}