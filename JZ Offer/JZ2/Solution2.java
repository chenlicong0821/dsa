import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    public String replaceSpace (String s) {
        StringBuilder res = new StringBuilder();
        if (s == null || s.length() == 0) {
            return res.toString();
        }
        // 可能最后一个字符也是空格，这里加个后缀方便split
        String n = s + " end";
        String[] array = n.split(" ");
        for (int i = 0; i < array.length - 1; i++) {
            res.append(array[i]);
            // 最后一项不用加%20
            if (i != array.length - 2) {
                res.append("%20");
            }
        }
        return String.valueOf(res);
    }
}