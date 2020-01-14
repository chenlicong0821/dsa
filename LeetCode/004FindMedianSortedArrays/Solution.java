class Solution {
    public double findMedianSortedArrays1(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        int left = (m+n+1)/2;
        int right = (m+n+2)/2;
        return (findKth(nums1, 0, nums2, 0, left) + findKth(nums1, 0, nums2, 0, right)) / 2.0;
    }

    public int findKth(int[] nums1, int i, int[] nums2, int j, int k) {
        // 如果len1已经为空，直接从nums2找；如果len2已经为空，直接从nums1找
        if (i >= nums1.length) return nums2[j+k-1];
        if (j >= nums2.length) return nums1[i+k-1];
        // 找第1个数，比较nums1[0]和nums2[0]谁更小即可
        if (k == 1) {
            return Math.min(nums1[i], nums2[j]);
        }

        int midVal1 = (i + k/2 -1) < nums1.length ? nums1[i + k/2 -1] : Integer.MAX_VALUE;
        int midVal2 = (j + k/2 -1) < nums2.length ? nums2[j + k/2 -1] : Integer.MAX_VALUE;
        if (midVal1 < midVal2) {
            return findKth(nums1, i + k/2, nums2, j, k - k/2);
        } else {
            return findKth(nums1, i, nums2, j + k/2, k - k/2);
        }
    }

    public double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int m = nums1.length;
        int n = nums2.length;
        // to ensure m<=n
        if (m > n) {
            int temp[] = nums1; nums1 = nums2; nums2 = temp;
            int tmp = m; m = n; n = tmp;
        }
        int iMin = 0, iMax = m, halfLen = (m + n + 1) / 2;
        while (iMin <= iMax) {
            int i = (iMin + iMax) / 2;
            int j = halfLen - i;
            if (i < iMax && nums1[i] < nums2[j-1]) {
                iMin = i + 1;   // i is too small
            }
            else if (i > iMin && nums1[i-1] > nums2[j]) {
                iMax = i - 1;   // i is too big
            }
            else {  // i is perfect
                int maxLeft = 0;
                if (i == 0) {maxLeft = nums2[j - 1];}
                else if (j == 0) {maxLeft = nums1[i - 1];}
                else {maxLeft = Math.max(nums1[i - 1], nums2[j - 1]);}
                if ((m+n)%2==1) {return maxLeft;}

                int minRight = 0;
                if (i == m) {minRight = nums2[j];}
                else if (j == n) {minRight = nums1[i];}
                else {minRight = Math.min(nums1[i], nums2[j]);}

                return (maxLeft + minRight)/2.0;
            }
        }

        return 0.0;
    }
}
