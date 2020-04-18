class Solution:
    def maxProduct1(self, nums: List[int]) -> int:
        if not nums: return 0

        dp = [[0 for _ in range(2)] for _ in range(2)]
        dp[0][0], dp[0][1], res = nums[0], nums[0], nums[0]

        for i in range(1, len(nums)):
            x, y = i % 2, (i - 1) % 2
            dp[x][0] = max(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i])
            dp[x][1] = min(dp[y][0] * nums[i], dp[y][1] * nums[i], nums[i])
            res = max(res, dp[x][0])

        return res

    def maxProduct(self, nums: List[int]) -> int:
        if not nums: return 0

        res, curMax, curMin = nums[0], nums[0], nums[0]
        for i in range(1, len(nums)):
            num = nums[i]
            curMax, curMin = curMax * num, curMin * num
            curMax, curMin = max(curMax, curMin, num), min(curMax, curMin, num)
            res = curMax if curMax > res else res

        return res
