class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        // 记录每个字符的最近出现位置
        unordered_map<char, int> map;
        int left = 0, res = 0;
        int n = s.size();
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (map.count(c)) {
                if (left < (map[c] + 1)) {
                    left = map[c] + 1;
                    // 左窗口至最后字符的子串已经小于最大子串
                    if (n - left < res) {
                        break;
                    }
                }
            }
            res = max(res, i - left + 1);
            map[c] = i;
        }

        return res;
    }
};