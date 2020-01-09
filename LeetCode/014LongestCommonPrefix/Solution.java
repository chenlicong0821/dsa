class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }

        String res = strs[0];
        for (int i = 1; i < strs.length; i++) {
            String str = strs[i];
            if (str.equals("") || res.equals("")) {
                return "";
            }

            int start = 0;
            while (start < res.length() && start < str.length() && str.charAt(start) == res.charAt(start)) {
                start++;
            }
            res = res.substring(0, start);
        }

        return res;
    }
}