class Solution {
public:
    int romanToInt(string s) {
        int res = 0;
        int n = s.size();
        unordered_map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int prev = mp[s[0]];
        for (int i = 0; i < n; ++i) {
            if (!i == 0 && prev < mp[s[i]]) {
                res += mp[s[i]] - 2*prev;
                // cout << mp[s[i]] << '-' << prev << endl;
            } else
                res += mp[s[i]];
            // cout << res << endl;

            prev = mp[s[i]];
        }
        return res;
    }
};