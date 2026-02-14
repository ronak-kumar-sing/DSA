#include <iostream>
using namespace std;

void print_arr(int arr[], int n)
{
  for (int i = 0; i < n; i++)
  {
    cout << arr[i] << " ";
  }
  cout << '\n';
}

void selection_sort(int arr[], int n)
{
  for (int i = 0; i < n - 1; i++)
  {
    int min = i;
    for (int j = i; j < n; j++)
    {
      min = arr[min] > arr[j] ? j : min;
    }
    swap(arr[i], arr[min]);
  }
}

int main()
{
  int arr[] = {13, 46, 24, 52, 20, 9};
  int arr1[] = {5, 4, 3, 2, 1};

  selection_sort(arr, 6);
  selection_sort(arr1, 5);
  print_arr(arr, 6);
  print_arr(arr1, 5);
  return 0;
}