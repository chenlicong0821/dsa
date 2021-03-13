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
        if (s==null){
            return null;
        }

        int spacenum = 0;
        for(int i = 0; i < s.length(); i++){
            if (s.charAt(i)==' ') {
                spacenum++;
            }
        }
        if (spacenum==0){
            return s;
        }

        StringBuffer newStr = new StringBuffer();
        int oldLength = s.length();
        newStr.setLength(oldLength + spacenum*2);
        for(int oldIndex=0,newIndex = 0; oldIndex < oldLength; oldIndex++){
            if (s.charAt(oldIndex)==' ') {
                newStr.setCharAt(newIndex++, '%');
                newStr.setCharAt(newIndex++, '2');
                newStr.setCharAt(newIndex++, '0');
            } else {
                newStr.setCharAt(newIndex++, s.charAt(oldIndex));
            }
        }

        return newStr.toString();
    }
}