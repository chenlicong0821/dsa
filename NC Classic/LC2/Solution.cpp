class Solution {
   public:
    /**
     *
     * @param tokens string字符串vector
     * @return int整型
     */
    int evalRPN(vector<string>& tokens) {
        stack<int> res;  //创建栈
        //遍历每一个输入，注意是字符串类型
        for (auto x : tokens) {
            if (x == "+" || x == "-" || x == "*" || x == "/") {
                //如果当前字符串是操作符
                if (res.size() < 2)
                    return 0;  //如果栈内数字不足两个，即无法进行运算，则返回0
                //依次将栈内两个数字出栈进行操作运算
                int a = res.top();
                res.pop();
                int b = res.top();
                res.pop();
                int c = 0;  //用c表示每次运算的结果
                if (x == "+")
                    c = b + a;
                else if (x == "-")
                    c = b - a;
                else if (x == "*")
                    c = b * a;
                else if (x == "/")
                    c = b / a;

                res.push(c);
            } else {
                //如果当前字符串是数字
                res.push(atoi(x.c_str()));
            }
        }
        return res.top();
    }
};