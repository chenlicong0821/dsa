class Solution {
    public int lengthOfLongestSubstring1(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int maxLen = 0;
        int l = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            Character c = s.charAt(i);
            if (map.containsKey(c)) {
                if (l < (map.get(c)+1)) {
                    l = map.get(c)+1;
                }
            }
            if (i-l+1 > maxLen) {
                maxLen = i-l+1;
            }
            map.put(c, i);
        }

        return maxLen;
    }

    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.length() == 0) {
            return 0;
        }

        int maxLen = 0;
        int l = 0;
        Map<Character, Integer> map = new HashMap<>();
        int n = s.length();
        for (int i = 0; i < n; i++) {
            Character c = s.charAt(i);
            if (map.containsKey(c)) {
                if (l < (map.get(c)+1)) {
                    l = map.get(c)+1;
                    // 左窗口至最后字符的子串已经小于最大子串
                    if (n-l < maxLen) {
                        break;
                    }
                }
            }
            if (i-l+1 > maxLen) {
                maxLen = i-l+1;
            }
            map.put(c, i);
        }

        return maxLen;
    }
}