#include <iostream>
#include <string>
using namespace std;

// Optimized function - clean and reusable
int scoreOfString(const string &s)
{
  if (s.length() < 2)
    return 0; // Edge case handling

  int score = 0;
  for (int i = 0; i < s.length() - 1; i++)
  {
    score += abs(s[i + 1] - s[i]);
  }
  return score;
}

int main()
{
  string s;
  cout << "Enter string: ";
  cin >> s;

  int result = scoreOfString(s);
  cout << "Score: " << result << endl;

  // Uncomment for debug output:
  // scoreOfStringDebug(s);

  return 0;
}