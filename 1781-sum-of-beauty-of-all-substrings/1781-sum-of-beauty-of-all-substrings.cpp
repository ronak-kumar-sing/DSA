class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int hash[26] = {0};
            for (int j = i; j < n; j++) {
                hash[s[j] - 'a']++;
                int maxFreq = 0;
                int minFreq = INT_MAX;
                for (int k = 0; k < 26; k++) {
                    if (hash[k] > 0) {
                        maxFreq = max(maxFreq, hash[k]);
                        minFreq = min(minFreq, hash[k]);
                    }
                }

                sum += maxFreq - minFreq;
            }
        }
        return sum;
    }
};