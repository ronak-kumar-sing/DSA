class Solution {
public:
    string removeOuterParentheses(string s) {
        string result ="";
        int depth  = 0;
        for(char i : s){
            if(i == '('){
                if(depth != 0) result += i;
                depth++;
            }else{
                if(depth != 1) result += i;
                depth--;
            }
        }
        return result;
    }
};