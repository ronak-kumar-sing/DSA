class Solution {

    private List<List<String>> ans = new ArrayList<>();
    private int[] hashLine;
    private int[] hashRight;
    private int[] hashLeft;

    public void solve(int row, int n, char[][] board) {
        if (row == n) {
            List<String> temp = new ArrayList<>();

            for (char[] i : board) {
                temp.add(new String(i));
            }

            ans.add(temp);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (hashLine[i] == 0 &&
                hashRight[i + row] == 0 &&
                hashLeft[(n - 1) + i - row] == 0) {

                board[row][i] = 'Q';
                hashLine[i] = 1;
                hashRight[i + row] = 1;
                hashLeft[(n - 1) + i - row] = 1;
                solve(row + 1, n, board);
                board[row][i] = '.';
                hashLine[i] = 0;
                hashRight[i + row] = 0;
                hashLeft[(n - 1) + i - row] = 0;
            }
        }
    }

    public List<List<String>> solveNQueens(int n) {
        hashLine = new int[n];
        hashRight = new int[2 * n - 1];
        hashLeft = new int[2 * n - 1];
        char[][] board = new char[n][n];
        for (char[] row : board) {
            Arrays.fill(row, '.');
        }
        solve(0, n, board);
        return ans;

    }
}