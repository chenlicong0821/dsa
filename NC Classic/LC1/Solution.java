import java.util.*;

/*
 * public class TreeNode {
 *   int val = 0;
 *   TreeNode left = null;
 *   TreeNode right = null;
 * }
 */

public class Solution {
    /**
     * 
     * @param root TreeNode类 
     * @return int整型
     */
    public int run (TreeNode root) {
        if (root == null) {
            return 0;
        }
        int left = run(root.left);
        int right = run(root.right);
        if (left*right > 0) {
            // 有两个子节点
            return (left>right ? right:left) + 1;
        }
        // 最多只有一个子节点
        return (left>right ? left:right) + 1;
    }
}