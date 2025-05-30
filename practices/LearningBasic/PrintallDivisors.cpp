#include <iostream>
using namespace std;
vector<int> printAllDivisors(int num)
{
  vector<int> value;
  for (int i = 1; i <= sqrt(num); ++i)
  {
    //* Check if i divides n
    //* without leaving a remainder
    if (num % i == 0)
    {
      value.push_back(i);
      //* Add the counterpart divisor
      //* if it's different from i
      //! Take reference from image folder
      if (i != num / i)
      {
        value.push_back(num / i);
      }
    }
  }
  sort(value.begin(), value.end());
  return value;
}
int main()
{
  int num;
  cin >> num;
  vector<int> value = printAllDivisors(num);

  cout << '[';
  for (int i : value)
  {
    cout << i;
    if (i != num)
      cout << ", ";
  }
  cout << ']';

  return 0;
}