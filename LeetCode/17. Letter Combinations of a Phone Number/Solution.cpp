class Solution {
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> table{
            {'0', " "}, {'1',"*"}, {'2', "abc"},
            {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
            {'6',"mno"}, {'7',"pqrs"},{'8',"tuv"},
            {'9',"wxyz"}};  
        vector<string> res;
        if(digits == "") return res;
        func(res, "", digits, table, 0);
        return res;
    }
    
    void func(vector<string> &res, string str, string &digits, unordered_map<char, string> &m, int index){
        if(str.size() == digits.size()){
            res.push_back(str);
            return;
        }

        for(char c : m[digits[index]]){
            func(res, str+c, digits, m, index+1);
        }
        return;
    }
};