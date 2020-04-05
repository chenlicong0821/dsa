class Solution {
    public int climbStairs(int n) {
        if (n <= 2) return n;
        int two_step_before = 1;
        int one_step_before = 2;
        int all_ways = 0;
        for (int i = 2; i < n; i++) {
            all_ways = one_step_before + two_step_before;
            two_step_before = one_step_before;
            one_step_before = all_ways;
        }

        return all_ways;
    }
}