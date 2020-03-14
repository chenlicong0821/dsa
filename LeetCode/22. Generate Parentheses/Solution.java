class Solution {
    public List<String> generateParenthesis(int n) {
        List<String> result = new ArrayList<String>();
        generateOneByOne("", result, n, n);
        return result;
    }

    private void generateOneByOne(String subList, List<String> result, int left, int right) {
        if (left == 0 && right == 0) {
            result.add(subList);
            return;
        }
        if (left > 0) {
            generateOneByOne(subList + "(", result, left - 1, right);
        }
        if (right > left) {
            generateOneByOne(subList + ")", result, left, right - 1);
        }
    }
}