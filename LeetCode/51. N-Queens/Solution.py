class Solution:
    def solveNQueens1(self, n: int) -> List[List[str]]:
        if n < 1: return []
        self.result = []
        self.cols = set()
        self.pie = set()
        self.na = set()
        self._DFS(n, 0, [])
        return [['.' * col + 'Q' + '.' * (n - col - 1) for col in sol] for sol in self.result]

    def _DFS(self, n, row, cur_state):
        if row >= n:
            self.result.append(cur_state)
            return

        for col in range(n):
            if col in self.cols or (row + col in self.pie) or (row - col in self.na):
                continue

            self.cols.add(col)
            self.pie.add(row + col)
            self.na.add(row - col)

            self._DFS(n, row + 1, cur_state + [col])

            self.cols.remove(col)
            self.pie.remove(row + col)
            self.na.remove(row - col)

    def solveNQueens(self, n: int) -> List[List[str]]:
        def DFS(cols, xy_sum, xy_diff):
            row = len(cols)
            if row == n:
                result.append(cols)
                return
            for col in range(n):
                if (col not in cols) and (row + col not in xy_sum) and (row - col not in xy_diff):
                    DFS(cols + [col], xy_sum + [row + col], xy_diff + [row - col])

        result = []
        DFS([], [], [])
        return [['.' * col + 'Q' + '.' * (n - col - 1) for col in sol] for sol in result]
