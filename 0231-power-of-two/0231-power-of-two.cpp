class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0) return false;
        bool isCo = false;
        while(n){
            if(isCo) return false;
            if(n & 1 == 1 ) isCo = true;
            n >>= 1;
        }
        return true;
    }
};