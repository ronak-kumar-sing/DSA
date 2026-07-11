class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        sort(s.begin(),s.end());
        vector<vector<char>> freq(n + 1);
        int cnt = 1;
        char prev = s[0];
        for (int i = 1; i < n; i++) {
            if (prev == s[i])
                cnt++;
            else {
                freq[cnt].push_back(prev);
                prev = s[i];
                cnt = 1;
            }
        }
        freq[cnt].push_back(prev);

        string res;
        for (int i = n; i > 0; i--) {
            if (freq[i].empty())
                continue;
            for (char j : freq[i]) {
                int k = i;
                while(k){
                    res += j;
                    k--;
                }
            }
        }

        return res;
    }
};