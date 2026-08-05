class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("(",res, n, 1, 0);
        return res;
    }

private:
    void dfs(string str, vector<string>& res, int n, int open, int close){
        if(close > open) return;

        if((str.size() == 2*n)){
            if(open == close)
                res.push_back(str);
            return;
        }

        dfs(str + ")", res, n, open, close + 1);
        dfs(str + "(", res, n, open + 1, close);
    }
};
