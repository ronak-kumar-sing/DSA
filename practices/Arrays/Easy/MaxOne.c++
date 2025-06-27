#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int findMaxConsecutiveOnes(vector<int> &nums)
{
  int maxC = 0;
  int cnt = 0;
  for (int i = 0; i < nums.size(); i++)
  {
    if (nums[i] == 1)
    {
      cnt++;
      maxC = max(cnt, maxC);
    }
    else
      cnt = 0;
  }
  return maxC;
}

int main()
{
  // Test cases
  vector<int> nums1 = {1, 1, 0, 1, 1, 1};
  vector<int> nums2 = {1, 0, 1, 1, 0, 1};
  vector<int> nums3 = {0, 0, 0, 0};
  vector<int> nums4 = {1, 1, 1, 1};

  cout << "Test 1: " << findMaxConsecutiveOnes(nums1) << " (Expected: 3)" << endl;
  cout << "Test 2: " << findMaxConsecutiveOnes(nums2) << " (Expected: 2)" << endl;
  cout << "Test 3: " << findMaxConsecutiveOnes(nums3) << " (Expected: 0)" << endl;
  cout << "Test 4: " << findMaxConsecutiveOnes(nums4) << " (Expected: 4)" << endl;

  return 0;
}