class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> hash;
        int n = nums.size();
        int start = 0;
        int maxLen = 0;
        for(int end = 0 ; end < n; end++){
            hash[nums[end]]++;

            while(hash[nums[end]] > k){
                hash[nums[start]]--;
                start++;
            }

            maxLen = max(maxLen , end - start + 1);
        }


        return maxLen;
    }
};