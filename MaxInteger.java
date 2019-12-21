/*
输入正整数n，输出含有同样一串数字的比n小的最大值
输入输出示例：

input  | output | 备注
---    |---     |---
5      | N/A    | 没有比它小的
32     | 23     |
56     | N/A    |
30     | N/A    | 比它小的03，最高位是0，无效
103    | N/A    | 比它小的031，最高位是0，无效
8918   | 8891   |
6523   | 6352   |
764325 | 756432 |
*/

import java.lang.System;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;

public class MaxInteger {
    public static void main(String[] args) {
        int[] numbs = new int[8];
        numbs[0] = 5;
        numbs[1] = 32;
        numbs[2] = 56;
        numbs[3] = 30;
        numbs[4] = 103;
        numbs[5] = 8918;
        numbs[6] = 6523;
        numbs[7] = 764325;
        for (int i = 0; i < numbs.length; i++) {
            System.out.println(func(numbs[i]));
        }
    }

    public static Integer func(int n){
        int m = n;
        List<Integer> lst = new ArrayList();
        // 这一串数字，存放至List，低位放在低地址
        while (m > 0){
            lst.add(m %10);
            m /= 10;
        }

        for (int i = 0; i < lst.size()-1; i++)
            for (int j = i + 1; j < lst.size(); j++) {
                // 若高位存在更大的数字，就尝试交换
                if (lst.get(i) < lst.get(j)) {
                    // 0需要交换到最高位，是无效的
                    if (j == lst.size() - 1 && lst.get(i) == 0) {
                        // return lst;
                        return -1;
                    }
                    // 比j更高的位维持不变，把小的数字放在高位j，剩下的大的数字尽量放在高位（列表中是高位在高地址，所以是由小到大升序排序）
                    Collections.swap(lst, i, j);
                    List<Integer> subLst = lst.subList(0, j);
                    Collections.sort(subLst);

                    // 根据列表信息，组合还原为对应数字
                    Integer ret = 0;
                    for (int k = lst.size()-1; k >= 0; k--) {
                        ret = (10 * ret) + lst.get(k);
                    }

                    return ret;
                }
            }

        // return lst;
        return -1;
    }
}
