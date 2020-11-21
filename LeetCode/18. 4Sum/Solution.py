class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        if len(nums) < 4:
            return []

        m = {}
        for i in range(len(nums)-1):
            for j in range(i+1, len(nums)):
                m.setdefault(nums[i]+nums[j], []).append((i, j))

        result = set()
        for a in range(len(nums)-1):
            for b in range(a+1, len(nums)):
                for c, d in m.get(target-nums[a]-nums[b], []):
                    temp = {a, b, c, d}
                    if len(temp) == 4:
                        result.add(tuple(sorted([nums[i] for i in temp])))

        result2 = []
        for temp in result:
            result2.append(list(temp))
        return result2
