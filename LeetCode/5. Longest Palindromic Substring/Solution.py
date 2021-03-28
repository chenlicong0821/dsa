class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s)
        if n < 2:
            return s

        dp = [[False] * n for _ in range(n)]
        maxLen = 1
        maxStart = 0
        for r in range(1,n):
            for l in range(r):
                if (s[l]==s[r]) and (r-l<=2 or dp[l+1][r-1]):
                    dp[l][r]=True
                    if r-l+1 > maxLen:
                        maxLen = r-l+1
                        maxStart = l

        return s[maxStart:maxStart+maxLen]
