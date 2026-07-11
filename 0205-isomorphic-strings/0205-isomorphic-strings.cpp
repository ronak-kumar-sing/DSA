class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mp;
        unordered_map<char, char> mp1;

        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (mp.empty() || (!mp.count(s[i]) && !mp1.count(t[i]))) {
                mp[s[i]] = t[i];
                mp1[t[i]] = s[i];
            } else if (mp[s[i]] != t[i] && mp1[t[i]] != s[i])
                return false;

            cout << mp1[t[i]] << "==" << s[i]<<endl;
            cout << mp[s[i]] << "==" << t[i]<<endl;
        }

        return true;
    }
};