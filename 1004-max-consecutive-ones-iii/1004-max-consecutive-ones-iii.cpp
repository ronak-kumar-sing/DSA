class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 0;
        int oneCnt = 0;
        int start = 0;
        for (int end = 0; end < n; end++) {
            if (nums[end] == 1)
                oneCnt++;
            while (oneCnt + k < end - start + 1) {
                if (nums[start] == 1)
                    oneCnt--;
                start++;
            }
            maxLen = max(maxLen, end - start + 1);
        }

        return maxLen;
    }
};