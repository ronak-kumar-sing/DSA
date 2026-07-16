class Solution {
  public:
    int setBits(int n) {
        // Code here
        int cnt = 0;
        while(n){
            if(n & 1) cnt++;
            n>>=1;
            
        }
        
        return cnt;
    }
};