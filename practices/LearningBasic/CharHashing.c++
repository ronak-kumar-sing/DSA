#include <iostream>
using namespace std;
// ! Only for samll Alphabet // Capital Alphabet

// * Sample Output
// abcideadc
// 5
// a c d b f
// int main()
// {
//   string s;
//   cin >> s;
//   int q;
//   cin >> q; // * No of Queries
//   //* PreComputing
//   int hash[26] = {0};
//   for (int i = 0; i < s.length(); i++)
//   {
//     hash[s[i] - 'a']++;
//   }
//   while (q--)
//   {
//     char c;
//     cin >> c;
//     // * fetch
//     cout << hash[c - 'a'] << " ";
//   }
//   return 0;
// }

// * -----------------------------------------------------------------------
// ! Include all the element in char

//* Sample OutPut
// Ronakkumar
// 5
// k a m u R

int main()
{
  string s;
  cin >> s;
  int q;
  cin >> q; // * No of Queries
  //* PreComputing
  int hash[256] = {0};
  for (int i = 0; i < s.length(); i++)
  {
    hash[s[i]]++; // remove the - 'a'
    //* Because now the char 256 started from 0 to 256 char So where is no need of - 'a'
  }
  while (q--)
  {
    char c;
    cin >> c;
    // * fetch
    cout << hash[c] << " ";
  }
  return 0;
}