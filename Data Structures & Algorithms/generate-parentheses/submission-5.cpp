class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs("(",res, n, 1, 0);
        return res;
    }

private:
    void dfs(string str, vector<string>& res, int n, int open, int close){
        if(close == open && open == n) {
            res.push_back(str);
            return;
        }
        if(close < open)
        dfs(str + ")", res, n, open, close + 1);
        if(open < n)
        dfs(str + "(", res, n, open + 1, close);
    }
};
