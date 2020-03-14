class Solution {
    public static void main(String[] args) {
        Solution solution = new Solution();

        System.out.println(solution.solveNQueens(5));
    }

    public List<List<String>> solveNQueens1(int n) {
        List<List<String>> result = new ArrayList<>();
        if (n == 0) return result;
        dfs(0, n, new HashSet<>(), new HashSet<>(), new HashSet<>(), result, new ArrayList<>());
        return result;
    }

    private void dfs(int row, int n, Set<Integer> cols, Set<Integer> pie, Set<Integer> na, List<List<String>> results, List<String> tempList) {
        if (row >= n) {
            if (tempList.size() == n) {
                results.add(new ArrayList<>(tempList));
            }
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols.contains(col) || pie.contains(row + col) || na.contains(row - col)) {
                continue;
            }

            cols.add(col);
            pie.add(row + col);
            na.add(row - col);

            String temp = getStr(n, col);
            tempList.add(temp);
            dfs(row + 1, n, cols, pie, na, results, tempList);

            cols.remove(col);
            pie.remove(row + col);
            na.remove(row - col);
            tempList.remove(temp);
        }
    }

    private String getStr(int n, int col) {
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i < n; i++) {
            if (i == col) {
                stringBuilder.append("Q");
            } else
                stringBuilder.append(".");
        }
        return stringBuilder.toString();
    }

    public List<List<String>> solveNQueens(int n) {
        List<List<String>> result = new ArrayList<>();
        helper(0, n, new boolean[n], new boolean[2 * n], new boolean[2 * n], new ArrayList<>(), result);
        return result;
    }

    private void helper(int row, int n, boolean[] cols, boolean[] xy_sum, boolean[] xy_diff, List<String> board,
                        List<List<String>> res) {
        if (row >= n) {
            res.add(new ArrayList<>(board));
            return;
        }
        for (int col = 0; col < n; col++) {
            int sum = row + col, diff = row - col + n;
            if (!cols[col] && !xy_sum[sum] && !xy_diff[diff]) {
                char[] rowStr = new char[n];
                Arrays.fill(rowStr, '.');
                rowStr[col] = 'Q';
                String temp = new String(rowStr);
                board.add(temp);
                cols[col] = true;
                xy_sum[sum] = true;
                xy_diff[diff] = true;
                helper(row + 1, n, cols, xy_sum, xy_diff, board, res);
                cols[col] = false;
                xy_sum[sum] = false;
                xy_diff[diff] = false;
                board.remove(temp);
            }
        }
    }
}