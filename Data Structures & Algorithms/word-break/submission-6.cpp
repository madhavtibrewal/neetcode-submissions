class Solution {
public:
    bool rec(string& s, vector<string>& wordDict, int i, unordered_map<int, bool>& dp){
        if(dp.find(i) != dp.end()) return dp[i];
        for(const auto& w : wordDict){
            if(i + w.size() <= s.size() && s.substr(i, w.length()) == w){
                if(rec(s, wordDict, i + w.size(), dp)){
                    return dp[i] = true;
                }
            }
        }

        return dp[i] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<int, bool> dp;
        dp[s.length()] = true;
        return rec(s, wordDict, 0, dp);
    }
};
