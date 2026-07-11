class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char , int> hash_table;

        for(char i : s){
            hash_table[i]++;
        }

        for(char i : t){
            hash_table[i]--;
        }
        
        for(auto i : hash_table){
            if(i.second != 0 ) return false; 
        }

        return true;
    }
};