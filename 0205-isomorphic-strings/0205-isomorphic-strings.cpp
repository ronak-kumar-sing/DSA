class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> map1(256 , -1);
        vector<int> map2(256 , -1);
        int n = s.size();

        for(int i = 0; i < n ; i++){
            if(map1[s[i]] != -1 && map1[s[i]] != t[i]) return false;
            else if(map2[t[i]] != -1 && map2[t[i]] != s[i]) return false;
            else{
                map1[s[i]] = t[i];
                map2[t[i]] = s[i];
            }
        }


        return true;
    }
};