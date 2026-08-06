class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> part;
        dfs(0, s, res, part);
        return res;
    }

private:
    bool isPal(string s, int start, int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++, end--;
        }
        return true;
    }
    void dfs(int i, string s, vector<vector<string>>& res, vector<string>& part){
        if(i == s.size()){
            res.push_back(part);
            return;
        }

        for(int j = i; j < s.size(); j++){
            if(isPal(s, i, j)){
                part.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, s, res, part);
                part.pop_back();
            }
        }

        return;
    }
};
