class Solution {
public:
    int myAtoi(string s) {
        long long res = 0;
        int sign = 1;
        int n = s.size();

        int i = 0;
        while (i < n && s[i] == ' ')
            i++;
        if (i >= n)
            return 0;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } else if (s[i] == '+')
            i++;
        for (; i < n; i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                res = (res * 10) + (s[i] - '0');
                if (sign == 1 && res > INT_MAX)
                    return INT_MAX;
                else if (sign == -1 && -res < INT_MIN)
                    return INT_MIN;
            } else
                break;
        }

        return sign * res;
    }
};