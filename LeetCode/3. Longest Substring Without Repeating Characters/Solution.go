func lengthOfLongestSubstring(s string) int {
    // 哈希集合，记录每个字符是否出现过
    m := map[byte]int{}
    n := len(s)
	left,res := 0,0
	for i := 0; i < n; i++ {
		ch := s[i]
		last,ok:=m[ch]
		if ok {
			if left < last+1 {
				left = last+1
				// 左窗口至最后字符的子串已经小于最大子串
				if n - left < res {
					break;
				}
			}
		}
		if res < i-left+1 {
			res = i-left+1
		}
		m[ch] = i
	}

	return res
}