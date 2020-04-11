class Solution:
    def minimumTotal(self, triangle: List[List[int]]) -> int:
        if not triangle: return 0
        
        res = triangle[-1]
        for i in range(len(triangle) - 2, -1, -1):
            for j in range(len(triangle[i])):
                res[j] = triangle[i][j] + min(res[j], res[j + 1])

        return res[0]
