class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int i = 0;
        int j = 0;
        while (i < n && j < m) {
            // pair<int , pair<int,int>> maxValIdx = {-1,{-1,-1}};
            if (i != 0 && mat[i - 1][j] > mat[i][j]) {
                i--;
                continue;
            }
            if (i != n - 1 && mat[i + 1][j] > mat[i][j]) {
                i++;
                continue;
            }
            if (j != 0 && mat[i][j - 1] > mat[i][j]) {
                j--;
                continue;
            }
            if (j != m - 1 && mat[i][j + 1] > mat[i][j]) {
                j++;
                continue;
            }
            return {i, j};
        }

        return {-1, -1};
    }
};