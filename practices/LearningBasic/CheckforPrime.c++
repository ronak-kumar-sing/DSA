#include <iostream>
using namespace std;

bool isPrime(int num) // O(√n)
{
  if (num <= 1)
    return false; // O(1)
  if (num == 2)
    return true; // O(1)
  if (num % 2 == 0)
    return false;                       // O(1)
  for (int i = 3; i * i <= num; i += 2) // O(√n)
  {
    if (num % i == 0)
    {
      return false;
    }
  }
  return true;
}

int main()
{
  int num;
  cin >> num;
  if (isPrime(num))
  {
    cout << num << " is a Prime Number";
  }
  else
  {
    cout << num << " is not a Prime Number";
  }
  return 0;
}