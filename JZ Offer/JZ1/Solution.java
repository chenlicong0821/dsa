public class Solution {
    public boolean Find(int target, int [][] array) {
        int rows = array.length;
        if (rows == 0){
            return false;
        }
        int cols = array[0].length;
        if (cols == 0) {
            return false;
        }

        // 从右上角开始查找
        int row = 0;
        int col = cols-1;
        while (row < rows && col >=0) {
            if (array[row][col] < target) {
                row++;
            } else if (array[row][col] > target){
                col--;
            } else {
                return true;
            }
        }

        return false;
    }
}