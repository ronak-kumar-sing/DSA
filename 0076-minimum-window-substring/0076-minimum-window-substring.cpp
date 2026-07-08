class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.empty()) return "";
        unordered_map<char , int > Tcount, Window;

        for(char i : t){
            Tcount[i]++;
        }

        int have = 0;
        int need = Tcount.size();

        pair<int,int> res = {-1 , -1};
        int len = INT_MAX;
        int l = 0;
        for(int r = 0 ; r < n ;r++){
            char c = s[r];
            Window[c]++;

            if(Tcount.count(c) && Window[c] == Tcount[c]) have++;

            while(have == need){
                if(len > r - l + 1){
                    res = {l,r};
                    len = r - l + 1;
                }
                Window[s[l]]--;
                if(Tcount.count(s[l]) && Window[s[l]] < Tcount[s[l]]) have--;
                l++;
            }

        }

        return len == INT_MAX ? "" : s.substr(res.first, len);
    }
};