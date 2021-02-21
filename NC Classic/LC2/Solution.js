/**
  * 
  * @param tokens string字符串一维数组 
  * @return int整型
  */
function evalRPN(tokens) {
    let flag = ['+', '-', '*', '/'];
    var res = [];
    for (const ch of tokens) {
        let index = flag.indexOf(ch);
        if (index !== -1) {
            const b = res.pop();
            const a = res.pop();
            const op = flag[index];
            const sum = eval(`${a}${op}(${b})`);
            res.push(parseInt(sum));    // 除法运算，sum可能出现浮点数，根据题目要求，统一转为整数
        } else {
            res.push(ch);
        }
    }

    return parseInt(res.pop());
}
module.exports = {
    evalRPN: evalRPN
};