class Solution {
    /* 优化的暴力
    我们可以考虑所有两两柱子之间形成的矩形面积，该矩形的高为它们之间最矮柱子的高度，宽为它们之间的距离，
    这样可以找到所要求的最大面积的矩形。我们可以用前一对柱子之间的最低高度来求出当前柱子对间的最低高度。
    用数学语言来表达，minheight=min(minheight,heights(j))，其中，heights(j) 是第j个柱子的高度。
    时间复杂度：O(n^2)。 需要枚举所有可能的柱子对。
    空间复杂度：O(1) 。不需要额外的空间。 */
    public int largestRectangleArea1(int[] heights) {
        int maxarea = 0;
        for (int i = 0; i < heights.length; i++) {
            int minheight = Integer.MAX_VALUE;
            for (int j = i; j < heights.length; j++) {
                minheight = Math.min(minheight, heights[j]);
                maxarea = Math.max(maxarea, minheight*(j-i+1));
            }
        }

        return maxarea;
    }

    /* 分治
    通过观察，可以发现，最大面积矩形存在于以下几种情况：
    1. 确定了最矮柱子以后，矩形的宽尽可能往两边延伸。
    2. 在最矮柱子左边的最大面积矩形（子问题）。
    3. 在最矮柱子右边的最大面积矩形（子问题）。
    举个例子：
    [6, 4, 5, 2, 4, 3, 9]
    这里最矮柱子高度为 2 。以 2 为高的最大子矩阵面积是 2x7=14 。现在，我们考虑上面提到的第二种和第三种情况。
    我们对高度为 2 柱子的左边和右边采用同样的过程。在 2 的左边， 4 是最小的，形成区域为 4x3=12 。将左边区域再继续分，
    矩形的面积分别为 6x1=6 和 5x1=5 。同样的，我们可以求出右边区域的面积为 3x3=9, 4x1=4 和 9x1=9 。因此，
    我们得到最大面积是 16 。

    时间复杂度：
    平均开销：O(nlogn)
    最坏情况：O(n^2)。如果数组中的数字是有序的，分治算法将没有任何优化效果。
    空间复杂度：O(n)。最坏情况下递归需要 O(n) 的空间。 */
    public int calculateArea(int[] heights, int start, int end) {
        if (start > end) {
            return 0;
        }
        int minindex = start;
        for (int i = start + 1; i <= end; i++) {
            if (heights[i] < heights[minindex]) {
                minindex = i;
            }
        }
        return Math.max(heights[minindex]*(end-start+1), Math.max(calculateArea(heights, start, minindex-1), calculateArea(heights, minindex+1, end)));
    }
    public int largestRectangleArea2(int[] heights) {
        return calculateArea(heights, 0, heights.length-1);
    }

    /* 栈
    在这种方法中，我们维护一个栈。一开始，我们把 -1 放进栈的顶部来表示开始。初始化时，按照从左到右的顺序，
    我们不断将柱子的序号放进栈中，直到遇到相邻柱子呈下降关系，也就是a[i−1]>a[i]。现在，我们开始将栈中的序号弹出，
    直到遇到stack[j]满足a[stack[j]]≤a[i]。每次我们弹出下标时，我们用弹出元素作为高形成的最大面积矩形的宽是
    当前元素与stack[top−1]之间的那些柱子。也就是当我们弹出stack[top]时，记当前元素在原数组中的下标为 i ，
    当前弹出元素为高的最大矩形面积为：
    (i−stack[top−1]−1)×a[stack[top]].
    更进一步，当我们到达数组的尾部时，我们将栈中剩余元素全部弹出栈。在弹出每一个元素是，我们用下面的式子来求面积：
    (heights.length−stack[top−1]-1)×a[stack[top]]，其中，stack[top]表示刚刚被弹出的元素。因此，我们可以通过每次比较
    新计算的矩形面积来获得最大的矩形面积。
    时间复杂度：O(n)。 nn 个数字每个会被压栈弹栈各一次。
    空间复杂度：O(n)。用来存放栈中元素。 */
    public int largestRectangleArea(int[] heights) {
        Stack<Integer> stack = new Stack<>();
        stack.push(-1);
        int maxarea = 0;
        for (int i = 0; i < heights.length; i++) {
            while (stack.peek() != -1 && heights[stack.peek()] > heights[i]) {
                maxarea = Math.max(maxarea, heights[stack.pop()] * (i - stack.peek() - 1));
            }
            stack.push(i);
        }
        while (stack.peek() != -1) {
            maxarea = Math.max(maxarea, heights[stack.pop()] * (heights.length - stack.peek() - 1));
        }

        return maxarea;
    }
}