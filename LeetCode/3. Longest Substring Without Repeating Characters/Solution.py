class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        # 记录每个字符的最近出现位置
        charDict = dict()
        left, ans = 0, 0
        n = len(s)
        for i in range(n):
            ch = s[i]
            if ch in charDict:
                if left < charDict[ch]+1:
                    left = charDict[ch]+1
                    # 左窗口至最后字符的子串已经小于最大子串
                    if n-left < ans:
                        break
            ans = max(ans, i-left+1)
            charDict[ch]=i

        return ans