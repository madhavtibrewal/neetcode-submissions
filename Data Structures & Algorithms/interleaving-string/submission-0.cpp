class Solution {
public:
    bool rec(string& s1, string& s2, string& s3, int i, int j, int k, vector<vector<int>>& dp){
        if(k == s3.size()) return true;
        if(dp[i][j] != -1) return dp[i][j];
        bool res = false;
        if(i < s1.size() && s1[i] == s3[k]){
            res = rec(s1, s2, s3, i + 1, j, k + 1, dp);
        }
        if(!res && j < s2.size() && s2[j] == s3[k]){
            res = rec(s1, s2, s3, i, j + 1, k + 1, dp); 
        }

        return dp[i][j] = res;
    }
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.size(), n = s2.size();
        if (s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return rec(s1, s2, s3, 0, 0 ,0, dp);   
    }
};
