#include <iostream>
using namespace std;
bool isArmstrongNumber(int num)
{
  int temp = num;
  int sum = 0;
  int digitCount = to_string(num).length();
  while (temp)
  {
    sum += pow(temp % 10, digitCount);
    temp /= 10;
  }
  return sum == num;
}
int main()
{
  int num;
  cin >> num;
  if (isArmstrongNumber(num))
  {
    cout << num << " is Armstrong Number";
  }
  else
  {
    cout << num << " not an Armstrong Number!";
  }
  return 0;
}