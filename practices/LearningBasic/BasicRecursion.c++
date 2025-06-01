#include <iostream>
using namespace std;

// * recursion :- when the function call's itself again and again
// * Until a specified condition is meet's

// * Print Sum of 1 to N;
// int summ(int n) // * functional way
// {
//   // Base case: stop recursion when n reaches 0 or 1
//   if (n <= 1)
//     return 1;
//   return n + summ(n - 1);
// }

// int main()
// {
//   int n;
//   cin >> n;
//   cout << summ(n) << endl;

//   return 0;
// }

// !----------------------------------------------------------------

// void summ(int n, int sum) // * parameteres way
// {
//   // Base case: stop recursion when n reaches 0 or 1
//   if (n < 1)
//   {
//     cout << sum;
//     return;
//   }
//   summ(n - 1, sum + n);
// }

// int main()
// {
//   int n;
//   cin >> n;
//   summ(n, 0);

//   return 0;
// }

// !----------------------------------------------------------------

int fact(int n)
{
  if (n == 1)
    return 1;
  return n * fact(n - 1);
}
int main()
{
  int n;
  cin >> n;
  cout << fact(n);
  return 0;
}