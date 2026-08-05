class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str;
        backtrack(0, 0, n, res, str);
        return res;
    }

    void backtrack(int open, int close, int n, vector<string>& res, string str){
        if(open == close && open == n){
            res.push_back(str);
        }

        if(open < n){
            backtrack(open + 1, close, n, res, str + "(");
        }
            if(close < open){
                backtrack(open, close + 1, n, res, str + ")");
            }
    }
};
