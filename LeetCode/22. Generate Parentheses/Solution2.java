class Solution {
    List<String> list = new ArrayList<>();
    public List<String> generateParenthesis(int n) {
        if (n <= 0) {
            return list;
        }
        process(0, 0, n, "");
        return list;
    }

    private void process(int left, int right, int sum, String tmp) {
        // 递归的第一步，确定终止条件，防止死循环。
        if (2*sum == tmp.length()) {
            list.add(tmp);
            return;
        }

        if (left < sum) {
            process(left+1, right, sum, tmp+"(");
        }
        if (left > right) {
            process(left, right+1, sum, tmp+")");
        }
    }
}