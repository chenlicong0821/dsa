class Solution {
    public int mySqrt1(int x) {
        if (x == 0 || x == 1) return x;
        int l = 0, r = x;
        int mid, res = x;
        while (l <= r) {
            mid = (l + r) / 2;
            if (mid == x / mid) {
                return mid;
            } else if (mid > x / mid) {
                r = mid - 1;
            } else {
                l = mid + 1;
                res = mid;
            }
        }
        return res;
    }

    public int mySqrt(int x) {
        long r = x;
        while (r * r > x) {
            r = (r + x / r) / 2;
        }
        return (int)r;
    }
}