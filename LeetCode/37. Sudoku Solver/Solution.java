class Solution {
    public void solveSudoku(char[][] board) {
        if (board == null || board.length == 0) return;
        solve(board);
    }

    private boolean solve(char[][] board) {
        for (int i = 0; i < board.length; i++)
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j] == '.') {
                    for (char c = '1'; c <= '9'; c++) {
                        if (isValid(board, i, j, c)) {
                            board[i][j] = c;
                            if (solve(board))
                                return true;
                            else
                                board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        return true;
    }

    private boolean isValid(char[][] board, int row, int col, char c) {
        int row1 = row / 3, col1 = col / 3;
        for (int i = 0; i < 9; i++) {
            if (board[i][col] == c) return false;   // check column
            if (board[row][i] == c) return false;   // check row
            if (board[3 * row1 + i / 3][3 * col1 + i % 3] == c) return false;   // check 3*3 block
        }
        return true;
    }
}