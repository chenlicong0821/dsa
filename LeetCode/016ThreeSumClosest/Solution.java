class Solution {
    public int threeSumClosest(int[] nums, int target) {
        assert nums.length > 2;

        Arrays.sort(nums);
        int left;
        int right;
        int sum;
        int res = 0;    // 记录返回结果
        int tmp = Integer.MAX_VALUE;    // 记录sum和target的差的绝对值
        for (int i = 0; i < nums.length - 2; i++) {
            left = i+1;
            right = nums.length - 1;
            while (left < right) {
                sum = nums[i] + nums[left] + nums[right];
                // 如果已经找到等于target的三个数，直接返回即可
                if (sum == target) {
                    return target;
                }
                if (Math.abs(sum - target) < tmp) {
                    tmp = Math.abs(sum - target);
                    res = sum;
                }
                if (sum < target) {
                    left++;
                }
                else {
                    right--;
                }
            }
        }

        return res;
    }
}