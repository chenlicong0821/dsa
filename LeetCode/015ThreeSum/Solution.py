class Solution:
    def threeSum1(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        res = set()
        for i, a in enumerate(nums[:-2]):
            target = set()
            for b in nums[i + 1:]:
                if b not in target:
                    target.add(-a - b)
                else:
                    res.add(tuple(sorted([a, -a - b, b])))
        return map(list, res)

    def threeSum2(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        nums.sort()
        res = set()
        for i, v in enumerate(nums[:-2]):
            if v > 0:
                break
            if i >= 1 and v == nums[i - 1]:
                continue
            target = set()
            for x in nums[i + 1:]:
                if x not in target:
                    target.add(-v - x)
                else:
                    res.add((v, -v - x, x))
        return map(list, res)

    def threeSum(self, nums: List[int]) -> List[List[int]]:
        if len(nums) < 3:
            return []
        nums.sort()
        res = []
        for i, v in enumerate(nums[:-2]):
            if v > 0:
                break
            if i > 0 and v == nums[i - 1]:
                continue
            l, r = i + 1, len(nums) - 1
            while l < r:
                s = v + nums[l] + nums[r]
                if s < 0:
                    l += 1
                elif s > 0:
                    r -= 1
                else:
                    res.append([v, nums[l], nums[r]])
                    while l < r and nums[l] == nums[l + 1]:
                        l += 1
                    while l < r and nums[r] == nums[r - 1]:
                        r -= 1
                    l += 1
                    r -= 1
        return res