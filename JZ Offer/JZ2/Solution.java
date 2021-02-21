public class Solution {
    public String replaceSpace(StringBuffer str) {
        if (str==null){
            return null;
        }

        int spacenum = 0;
        for(int i = 0; i < str.length(); i++){
            if (str.charAt(i)==' ') {
                spacenum++;
            }
        }

        int oldLength = str.length();
        int oldIndex = oldLength - 1;
        int newLength = oldLength + spacenum*2;
        str.setLength(newLength);
        int newIndex = newLength - 1;
        for(; oldIndex < newIndex && oldIndex >=0; oldIndex--){
            if (str.charAt(oldIndex)==' ') {
                str.setCharAt(newIndex--, '0');
                str.setCharAt(newIndex--, '2');
                str.setCharAt(newIndex--, '%');
            } else {
                str.setCharAt(newIndex--, str.charAt(oldIndex));
            }
        }

        return str.toString();
    }
}