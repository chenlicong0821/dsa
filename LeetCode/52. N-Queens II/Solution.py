class Solution:
    def totalNQueens(self, n: int) -> int:
        if n < 1: return 0
        self.count = 0
        self.DFS(n, 0, 0, 0, 0)
        return self.count

    def DFS(self, n, row, cols, pie, na):
        # recursion terminator
        if row >= n:
            self.count += 1
            return

        bits = (~(cols | pie | na)) & ((1 << n) - 1)  # 得到当前所有的空位

        while bits:
            p = bits & -bits  # 取到最低位的1
            self.DFS(n, row + 1, cols | p, (pie | p) >> 1, (na | p) << 1)
            bits = bits & (bits - 1)  # 去掉最低位的1
