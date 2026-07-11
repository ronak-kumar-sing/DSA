class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int j;
            for (j = 0; j < n; j++) {
                if (s[j] != goal[(i + j) % n])
                    break;
            }
            if (j == n)
                return true;
        }
        return false;
    }
};