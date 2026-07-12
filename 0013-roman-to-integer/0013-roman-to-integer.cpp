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

        for (int i = 0; i < n; ++i) {
            if (i != n - 1 &&
                (s[i] == 'I' && (s[i + 1] == 'V' || s[i + 1] == 'X'))) {
                res += mp[s[i + 1]] - 1;
                i++;
            } else if (i != n - 1 &&
                       (s[i] == 'X' && (s[i + 1] == 'L' || s[i + 1] == 'C'))) {
                res += mp[s[i + 1]] - 10;
                i++;
            } else if (i != n - 1 &&
                       (s[i] == 'C' && (s[i + 1] == 'D' || s[i + 1] == 'M'))) {
                res += mp[s[i + 1]] - 100;
                i++;
            } else {
                res += mp[s[i]];
            }
        }
        return res;
    }
};