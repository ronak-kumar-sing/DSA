class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char , int > mp;

        for(char i : s){
            mp[i]++;
        }

        string ans;
        while(!mp.empty()){
            int Max = 0;
            char c;
            for(auto i : mp){
                if(Max < i.second){
                    Max = i.second;
                    c = i.first;
                }
            }
            while(Max--){
                ans += c;
            }
            mp.erase(c);
        }

        return ans;
    }
};