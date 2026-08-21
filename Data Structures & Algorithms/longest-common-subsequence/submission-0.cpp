class Solution {
public:
    int rec(string text1, string text2, int i, int j, vector<vector<int>>& dp){
        if(i >= text1.size() || j >= text2.size()) return 0;
        int total = 0;

        if(dp[i][j] != -1) return dp[i][j];
        
        if(text1[i] == text2[j]){
            total = 1 + rec(text1, text2, i + 1, j + 1, dp);
        }
        else{
            total += max(rec(text1, text2, i, j + 1, dp), rec(text1, text2, i + 1, j, dp));
        }

        return dp[i][j] = total;
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));

        return rec(text1, text2, 0, 0, dp);
    }
};
