class Solution {
    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int help = 1;
        int tmp = x;
        while (tmp >= 10) {
            help *= 10;
            tmp /= 10;
        }
        while (x != 0) {
            if (x % 10 != x / help) {
                return false;
            }
            x = x % help / 10;
            help /= 100;
        }

        return true;
    }
}