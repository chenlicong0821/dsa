class Solution:
    def __init__(self):
        self.dx = [-1, 1, 0, 0]
        self.dy = [0, 0, -1, 1]

    def numIslands(self, grid: List[List[str]]) -> int:
        if not (grid and grid[0]):
            return 0

        self.max_x = len(grid[0])
        self.max_y = len(grid)
        self.grid = grid
        self.visited = set()

        # return sum([self.floodfill_DFS(y, x) for x in range(self.max_x) for y in range(self.max_y)])
        return sum([self.floodfill_BFS(y, x) for x in range(self.max_x) for y in range(self.max_y)])

    def floodfill_DFS(self, y, x):
        if not self._is_valid(y, x):
            return 0

        self.visited.add((y, x))
        for k in range(4):
            self.floodfill_DFS(y+self.dy[k], x+self.dx[k])
        return 1

    def floodfill_BFS(self, y, x):
        if not self._is_valid(y, x):
            return 0

        self.visited.add((y, x))
        queue = collections.deque()
        queue.append((y, x))

        while queue:
            cur_y, cur_x = queue.popleft()
            for k in range(4):
                new_y, new_x = cur_y+self.dy[k], cur_x+self.dx[k]
                if self._is_valid(new_y, new_x):
                    self.visited.add((new_y, new_x))
                    queue.append((new_y, new_x))

        return 1

    def _is_valid(self, y, x):
        if y < 0 or y >= self.max_y or x < 0 or x >= self.max_x:
            return False
        if self.grid[y][x] == '0' or ((y, x) in self.visited):
            return False

        return True
