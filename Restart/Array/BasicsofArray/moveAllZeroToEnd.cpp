#include <iostream>
using namespace std;
int main()
{
  int arr[] = {4, 0, 0, 0, 1, 0};
  for (int i = 0; i < 6; i++)
  {
    for (int j = i + 1; j < 6; j++)
    {
      if (arr[i] == 0 && arr[j] != 0)
      {
        swap(arr[i], arr[j]);
        break;
      }
    }

    // * To print
  }
  for (int i = 0; i < 6; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
  return 0;
}