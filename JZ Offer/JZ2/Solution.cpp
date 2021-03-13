class Solution {
   public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param s string字符串
     * @return string字符串
     */
    string replaceSpace(string s) {
        if (s.empty())
            return s;

        string ans = "";
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') {
                ans += "%20";
            } else {
                ans += s[i];
            }
        }

        return ans;
    }
};