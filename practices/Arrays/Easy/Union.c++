#include <iostream>
#include <set>
#include <map>
using namespace std;

//* Using Set
// TC : O((m + n) log(m + n))
// Space Complexity : O(m + n)
vector<int> setUnion(int arr1[], int arr2[], int n, int m)
{
  set<int> s;
  vector<int> Union;
  for (int i = 0; i < n; i++)
  {
    s.insert(arr1[i]);
  }
  for (int i = 0; i < m; i++)
  {
    s.insert(arr2[i]);
  }

  for (auto it : s)
  {
    Union.push_back(it);
  }
  return Union;
}
//* Using Map
// TC : O((m + n) log(m + n))
// Space Complexity : O(m + n)

vector<int> mapUnion(int arr1[], int arr2[], int n, int m)
{
  map<int, int> mpp;
  vector<int> Union;
  for (int i = 0; i < n; i++)
  {
    mpp[arr1[i]]++;
  }
  for (int i = 0; i < m; i++)
  {
    mpp[arr2[i]]++;
  }
  for (auto it : mpp)
  {
    Union.push_back(it.first);
  }
  return Union;
}

// * using TowPointer

// * Using the property that the arrays are sorted we can bring down the time complexity from

// * O((m + n) log(m + n)) TO O(m + n).

vector<int> usingTowPointer(int arr1[], int arr2[], int n, int m)
{
  vector<int> Union;
  int j = 0, i = 0;

  while (i < n && j < m)
  {
    if (arr1[i] <= arr2[j])
    {
      if (Union.size() == 0 || Union.back() != arr1[i])
        Union.push_back(arr1[i]);
      i++;
    }
    else
    {
      if (Union.size() == 0 || Union.back() != arr2[j])
        Union.push_back(arr2[j]);
      j++;
    }
  }
  while (i < n)
  {
    if (Union.size() == 0 || Union.back() != arr1[i])
      Union.push_back(arr1[i]);
    i++;
  }
  while (j < m)
  {
    if (Union.size() == 0 || Union.back() != arr2[j])
      Union.push_back(arr2[j]);
    j++;
  }

  return Union;
}

int main()
{
  // Sample case:
  // 5
  // 1 2 3 4 5
  // 5
  // 3 4 5 6 7
  // Expected Union: [1, 2, 3, 4, 5, 6, 7]

  int n1, n2;

  cout << "Enter size of first array: ";
  cin >> n1;
  int arr1[n1];

  cout << "Enter elements of first array: ";
  for (int i = 0; i < n1; i++)
  {
    cin >> arr1[i];
  }

  cout << "Enter size of second array: ";
  cin >> n2;
  int arr2[n2];

  cout << "Enter elements of second array: ";
  for (int i = 0; i < n2; i++)
  {
    cin >> arr2[i];
  }

  // vector<int> result = setUnion(arr1, arr2, n1, n2);
  // vector<int> result = mapUnion(arr1, arr2, n1, n2);
  vector<int> result = usingTowPointer(arr1, arr2, n1, n2);

  cout << "Union: ";
  for (int x : result)
  {
    cout << x << " ";
  }
  cout << endl;

  return 0;
}