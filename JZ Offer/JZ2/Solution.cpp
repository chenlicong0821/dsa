class Solution {
   public:
    void replaceSpace(char* str, int length) {
        if (str == nullptr || length <= 0)
            return;  // 判空操作

        int cnt = 0;  // 空格的个数
        for (int i = 0; i < length; ++i) {
            if (str[i] == ' ')
                cnt++;
        }
        if (cnt == 0)
            return;  // 没有空格，直接返回

        int newIndex = length - 1 + cnt * 2;
        for (int i = length - 1; i < newIndex && i >= 0; --i) {
            if (str[i] == ' ') {
                str[newIndex--] = '0';
                str[newIndex--] = '2';
                str[newIndex--] = '%';
            } else {
                str[newIndex--] = str[i];
            }
        }

        return;
    }
};