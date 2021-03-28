func longestPalindrome(s string) string {
	n := len(s)
	if n < 2 {
		return s
	}
	dp := make([][]bool, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]bool, n)
	}
	maxLen := 1
	maxStart := 0
	for r := 1; r < n; r++ {
		for l := 0; l < r; l++ {
			if (s[l] == s[r]) && (r-l <= 2 || dp[l+1][r-1]) {
				dp[l][r] = true
				if r-l+1 > maxLen {
					maxLen = r - l + 1
					maxStart = l
				}
			}
		}
	}
	return s[maxStart : maxStart+maxLen]
}