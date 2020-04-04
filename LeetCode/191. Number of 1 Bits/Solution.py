class Solution:
    def hammingWeight1(self, n: int) -> int:
        res = 0
        mask = 1
        for i in range(32):
            if n & mask:
                res += 1
            mask = mask << 1

        return res

    def hammingWeight(self, n: int) -> int:
        res = 0
        while n:
            if n & 1:
                res += 1
            n = n >> 1

        return res
