class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not (grid and grid[0]):
            return 0

        m, n = len(grid), len(grid[0])

        def sink(i, j):
            if 0 <= i < m and 0 <= j < n and grid[i][j] == '1':
                grid[i][j] = '0'
                list(map(sink, (i, i, i-1, i+1), (j-1, j+1, j, j)))
                return 1
            return 0

        return sum(sink(i, j) for i in range(m) for j in range(n))
