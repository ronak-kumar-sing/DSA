#include <iostream>
#include <vector>
using namespace std;

// * Using Two Pointer

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

int main()
{
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++)
    cin >> arr[i];

  cout << "Original array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;

  RearrageArray(arr, n);

  cout << "Rearranged array: ";
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
  cout << endl;
  return 0;
}