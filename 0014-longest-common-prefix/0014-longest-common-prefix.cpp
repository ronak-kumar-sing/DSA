class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int n = strs.size();
        for(int i = 1 ; i < n ;i++){
            int m = res.size();
            string prev = res;
            res = "";
            int k= strs[i].size();
            for(int j = 0 ; j < m && j < k ; j++){
                if(strs[i][j] == prev[j]) res+= prev[j];
                else break;
            }
            if(res.empty()) return "";
        }

        return res;
    }
};