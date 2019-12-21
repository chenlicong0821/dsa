"""
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
"""


def func(num):
    m = num
    lst = []
    # 这一串数字，存放至List，低位放在低地址
    while m > 0:
        lst.append(m % 10)
        m = int(m / 10)

    lst_len = len(lst)
    i = 0
    while i < lst_len - 1:
        j = i + 1
        while j < lst_len:
            # 若高位存在更大的数字，就尝试交换
            if lst[i] < lst[j]:
                # 0需要交换到最高位，是无效的
                if j == lst_len - 1 and lst[i] == 0:
                    return lst
                # 比j更高的位维持不变，把小的数字放在高位j，剩下的大的数字尽量放在高位（列表中是高位在高地址，所以是由小到大升序排序）
                lst[i], lst[j] = lst[j], lst[i]
                lst = sorted(lst[:j]) + lst[j:]
                k = lst_len - 1
                ret = 0

                # 根据列表信息，组合还原为对应数字
                while k >= 0:
                    ret = 10 * ret + lst[k]
                    k -= 1
                return ret
            j += 1
        i += 1

    return lst


nums = [5, 32, 56, 30, 103, 8918, 6523, 764325]
for n in nums:
    print(func(n))
