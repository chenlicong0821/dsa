class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        self.list = []
        self.num = n
        self._gen(0, 0, "")
        return self.list

    def _gen(self, left, right, result):
        if left == self.num and right == self.num:
            self.list.append(result)
            return
        if left < self.num:
            self._gen(left + 1, right, result + "(")
        if left > right:
            self._gen(left, right + 1, result + ")")
