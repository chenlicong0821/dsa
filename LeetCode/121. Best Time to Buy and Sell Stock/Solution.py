class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0

        res = 0
        profit = [[0 for _ in range(3)] for _ in range(len(prices))]
        # 初始利润
        profit[0][0], profit[0][1], profit[0][2] = 0, -prices[0], 0

        for i in range(1, len(prices)):
            # 无持仓：之前无持仓，当天不动
            profit[i][0] = profit[i - 1][0]
            # 有持仓：之前无持仓，当天买入；之前已持仓，当天不动。有持仓时profit是负数，max运算就是期望以更低价格买入
            profit[i][1] = max(profit[i - 1][0] - prices[i], profit[i - 1][1])
            # 已卖出：之前有持仓，当天卖出
            profit[i][2] = profit[i - 1][1] + prices[i]
            res = max(res, profit[i][0], profit[i][1], profit[i][2])

        return res
