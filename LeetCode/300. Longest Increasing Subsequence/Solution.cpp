class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> res;
        for (int i=0;i<nums.size();i++){
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it==res.end()){
                res.push_back(nums[i]); // 增加数组元素
            } else {
                *it=nums[i];    // 替换
            }
        }

        return res.size();
    }
};