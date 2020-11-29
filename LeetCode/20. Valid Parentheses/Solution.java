class Solution {
    public boolean isValid(String s) {
        int n = s.length();
        if (n % 2 != 0) {
            return false;
        }
        Map<Character, Character> map = new HashMap<>();
        map.put('(', ')');
        map.put('{', '}');
        map.put('[', ']');

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < n; i++) {
            char c = s.charAt(i);
            if (map.containsKey(c)) {
                // 左括号入栈
                // 剪枝：stack元素过多的话，s后半部全是有括号的时候也无法匹配
                if (stack.size()+1 <= n-i-1) {
                    stack.push(c);
                    continue;
                }
            } else {
                // 右括号与栈中的左括号匹配
                if (!stack.empty() && c == map.get(stack.pop())){
                    continue;
                }
            }
            return false;
        }

        return stack.empty();
    }
}