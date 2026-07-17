class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int hash[26] = {0};
        int maxVal = 0;
        int len  = 0;
        int start = 0;
        for(int end = 0 ; end < n ; end++){
            hash[s[end] - 'A']++;
            if(hash[s[end] - 'A'] > maxVal){
                maxVal = hash[s[end] - 'A'];
            }
            while(maxVal + k < end - start + 1){
                hash[s[start] - 'A']--;
                start++;
            }

            len = max(len , end - start + 1);

        }

        return len;
    }
};