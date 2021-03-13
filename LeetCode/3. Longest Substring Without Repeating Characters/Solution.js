/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
    // 记录每个字符的最近出现位置
    const charDict = {}
    let left = 0
    let ans = 0
    const n = s.length
    for (let i = 0; i < n; ++i) {
        const ch = s[i]
        if (ch in charDict) {
            if (left < charDict[ch] + 1) {
                left = charDict[ch] + 1
                // 左窗口至最后字符的子串已经小于最大子串
                if (n - left < ans) {
                    break
                }
            }
        }
        ans = Math.max(ans, i - left + 1)
        charDict[ch] = i
    }

    return ans
}