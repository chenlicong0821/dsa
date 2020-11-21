class Solution
{
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target)
    {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //首先排序
        if (nums.size() < 4)
            return {};

        for (int z = 0; z < nums.size() - 3; z++)
        {
            if (z > 0 && nums[z] == nums[z - 1])
                continue;
            int newTarget = target - nums[z]; // 将四数之和转化为3数

            for (int k = z + 1; k < nums.size() - 2; k++)
            { // 三数变成两数

                if (k > z + 1 && nums[k] == nums[k - 1])
                    continue;
                int newTarget2 = newTarget - nums[k];
                int i = k + 1, j = nums.size() - 1;
                while (i < j)
                { // 两数之和直接套用《两数之和2》的题
                    if (nums[i] + nums[j] == newTarget2)
                    {
                        res.push_back({nums[z], nums[k], nums[i], nums[j]});
                        while (i < j && nums[i] == nums[i + 1])
                            ++i; //注意去重
                        ++i;
                        while (i < j && nums[j] == nums[j - 1])
                            --j;
                        --j;
                    }
                    else if (nums[i] + nums[j] < newTarget2)
                        ++i;
                    else
                        --j;
                }
            }
        }
        return res;
    }
};