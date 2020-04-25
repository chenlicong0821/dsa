class Solution {
    public int maxProfit1(int[] prices) {
        int hold1 = Integer.MIN_VALUE, hold2 = Integer.MIN_VALUE;
        int release1 = 0, release2 = 0;
        for (int i : prices) {                          // Assume we only have 0 money at first
            release2 = Math.max(release2, hold2 + i);   // The maximum if we've just sold 2nd stock so far.
            hold2 = Math.max(hold2, release1 - i);      // The maximum if we've just buy  2nd stock so far.
            release1 = Math.max(release1, hold1 + i);   // The maximum if we've just sold 1nd stock so far.
            hold1 = Math.max(hold1, -i);                // The maximum if we've just buy  1st stock so far.
        }
        return release2;    // Since release1 is initiated as 0, so release2 will always higher than release1.
    }

    public int maxProfit(int[] prices) {
        /**
         对于任意一天考虑四个变量:
         fstBuy: 在该天第一次买入股票可获得的最大收益
         fstSell: 在该天第一次卖出股票可获得的最大收益
         secBuy: 在该天第二次买入股票可获得的最大收益
         secSell: 在该天第二次卖出股票可获得的最大收益
         分别对四个变量进行相应的更新, 最后secSell就是最大
         收益值(secSell >= fstSell)
         **/
        int fstBuy = Integer.MIN_VALUE, fstSell = 0;
        int secBuy = Integer.MIN_VALUE, secSell = 0;
        for (int p : prices) {
            fstBuy = Math.max(fstBuy, -p);
            fstSell = Math.max(fstSell, fstBuy + p);
            secBuy = Math.max(secBuy, fstSell - p);
            secSell = Math.max(secSell, secBuy + p);
        }
        return secSell;
    }
}