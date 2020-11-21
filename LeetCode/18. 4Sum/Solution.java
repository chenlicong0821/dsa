class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> result = new ArrayList<>();
        if (nums == null || nums.length < 4) {
            return result;
        }

        Arrays.sort(nums);
        int length = nums.length;
        /*定义4个指针first，second，third，fourth  first从0开始遍历，second从first+1开始遍历，third指向second+1，fourth指向数组最后一个数*/
        for (int first = 0; first < length - 3; first++) {
            /*当first的值与前面的值相等时忽略*/
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏*/
            int min1 = nums[first] + nums[first + 1] + nums[first + 2] + nums[first + 3];
            if (min1 > target) {
                break;
            }
            /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，忽略*/
            int max1 = nums[first] + nums[length - 3] + nums[length - 2] + nums[length - 1];
            if (max1 < target) {
                continue;
            }
            /*第二层循环second，初始值指向first+1*/
            for (int second = first + 1; second < length - 2; second++) {
                /*当second的值与前面的值相等时忽略*/
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                /*定义指针third指向second+1*/
                int third = second + 1;
                /*定义指针fourth指向数组末尾*/
                int fourth = length - 1;
                /*获取当前最小值，如果最小值比目标值大，说明后面越来越大的值根本没戏，剪枝操作*/
                int min2 = nums[first] + nums[second] + nums[third] + nums[third + 1];
                if (min2 > target) {
                    continue;
                }
                /*获取当前最大值，如果最大值比目标值小，说明后面越来越小的值根本没戏，剪枝操作*/
                int max2 = nums[first] + nums[second] + nums[fourth - 1] + nums[fourth];
                if (max2 < target) {
                    continue;
                }
                /*开始third指针和fourth指针的表演，计算当前和，如果等于目标值，third++并去重，fourth--并去重，当当前和大于目标值时fourth--，当当前和小于目标值时third++*/
                while (third < fourth) {
                    int curr = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (curr == target) {
                        result.add(Arrays.asList(nums[first], nums[second], nums[third], nums[fourth]));
                        third++;
                        while (third < fourth && nums[third] == nums[third - 1]) {
                            third++;
                        }
                        fourth--;
                        while (third < fourth && nums[fourth] == nums[fourth + 1]) {
                            fourth--;
                        }
                    } else if (curr > target) {
                        fourth--;
                    } else {
                        third++;
                    }
                }
            }
        }
        return result;
    }
}