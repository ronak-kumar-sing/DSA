class Solution {
public:
    int binarySearch(vector<int>& arr){
        sort(arr.begin(),arr.end());
        int left = 0;
        int right = arr.size() - 1;


        while(left <= right){
            int mid = left + (right - left)/2;

            if(arr[mid] == 0){
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return left;
    }
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        pair<int , int > result = {0,0};
        for(int i = 0 ; i < n ; i++){
            int k = binarySearch(mat[i]);
            int freq = m - k;
            if(result.second < freq) result = {i,freq};
        }

        return {result.first, result.second};
    }
};