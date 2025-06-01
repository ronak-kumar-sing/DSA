#include <iostream>
#include <map>
using namespace std;

//* Sample OutPut
// 5
// 2 3  100092 12 100092
// 5
// 2 4 100092 32321 12 3

int main()
{
  int n;
  cin >> n;
  int arr[n];
  map<int, int> mpp;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
    //* PreComputing
    mpp[arr[i]]++;
  }

  // for (auto it : mpp)
  // {
  //   cout << it.first << " -> " << it.second << "\n";
  // }

  int q; // no of queries
  cin >> q;
  while (q--)
  {
    int num;
    cin >> num;
    cout << mpp[num] << " ";
  }
  return 0;
}