class Solution {
public:
    string reverseWords(string s) {
        int i = s.size() - 1;
        if(i == 0) return s;
        string result;
        while (i > 0) {
            while (i >= 0 && s[i] == ' ')
                i--;

            if (i < 0)
                return result;
            int last = i;

            while (i >= 0 && s[i] != ' ')
                i--;
            int first = i + 1;
            if (!result.empty()) {
                result += ' ';
            }
            result += s.substr(first, last - first + 1);
        }
        return result;
    }
};