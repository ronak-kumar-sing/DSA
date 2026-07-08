class Solution {
public:

    bool isEatAl(vector<int>& piles, int h, int mid){
        int curr = 0;
        for(auto i : piles){
            curr += ceil(i/(double)mid);
            if(h < curr) return false;
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int right = INT_MIN;

        for(auto i : piles){
            right = max(right , i);
        }

        int left = 1;
        
        int ans = -1;

        while(left <= right){
            int mid = left + (right - left)/2;

            if(isEatAl(piles, h ,mid)){
                ans = mid;
                right = mid - 1;
            }else{
                left = mid + 1;
            }
        }

        return ans;
    }
};