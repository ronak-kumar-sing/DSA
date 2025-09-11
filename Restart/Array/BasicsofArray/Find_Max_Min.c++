#include <iostream>
using namespace std;

int Min(int arr[], int n)
{
  int Min = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] < Min)
    {
      Min = arr[i];
    }
  }
  return Min;
}

int Max(int arr[], int n)
{
  int Max = arr[0];
  for (int i = 0; i < n; i++)
  {
    if (arr[i] > Max)
    {
      Max = arr[i];
    }
  }
  return Max;
}

int main()
{
  int n;
  cout << "Enter Your length : ";
  cin >> n;
  cout << "Enter Your Array : ";
  int arr[100];
  for (int i = 0; i < n; i++)
    cin >> arr[i];
  cout << "Max :" << Max(arr, n);
  cout << "\nMin :" << Min(arr, n);

  return 0;
}