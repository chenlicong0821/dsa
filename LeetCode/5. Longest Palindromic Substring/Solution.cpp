class Solution {
   public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n < 2) {
            return s;
        }
        vector<vector<bool>> dp(n, vector<bool>(n));
        int maxLen = 1;
        int maxStart = 0;
        for (int r = 1; r < n; r++) {
            for (int l = 0; l < r; l++) {
                if ((s[l] == s[r]) && (r - l <= 2 || dp[l + 1][r - 1])) {
                    dp[l][r] = true;
                    if (r - l + 1 > maxLen) {
                        maxLen = r - l + 1;
                        maxStart = l;
                    }
                }
            }
        }
        return s.substr(maxStart, maxLen);
    }
};