class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double result;
        
        int i = 0;
        int j = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> nums;
        while(i < n && j < m){ // O(n1 + n2)
            if(nums1[i] <= nums2[j]){
                nums.push_back(nums1[i++]);
            }else{
                nums.push_back(nums2[j++]);
            }
        }
        while(i < n){
            nums.push_back(nums1[i++]);
        }

        while(j < m){
            nums.push_back(nums2[j++]);
        }
        int sumlen = n+m;
        if(sumlen %2 == 0){
            result = (double)(nums[sumlen/2] + nums[(sumlen/2) -1])/2;
        }else{
            result = (double)nums[sumlen/2];
        }

        return result;
    }
};