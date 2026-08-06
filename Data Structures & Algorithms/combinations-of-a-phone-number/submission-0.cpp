class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> res;
        if(digits.empty()){
            return res;
        }
        map<char, string> digitCharsMap = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        string comb;
        dfs(0, digits, digitCharsMap, res, comb);

        return res;
    }

private:
    void dfs(int i, const string& digits, map<char, string>& digitCharsMap, vector<string>& res, string& comb){
        if(i == digits.size()){
            res.push_back(comb);
            return;
        }

        for(char c : digitCharsMap[digits[i]]){
            comb += c;
            dfs(i + 1, digits, digitCharsMap, res, comb);
            comb.pop_back();
        }

        return;
    }
};
