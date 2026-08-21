class Solution {
public:
    int rec(string& word1, string& word2, int i, int j, int m, int n, vector<vector<int>>& dp){
        if(i == m) return n - j;
        if(j == n) return m - i;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = rec(word1, word2, i + 1, j + 1, m, n, dp);

        int res = 1 + min({rec(word1, word2, i + 1, j + 1, m, n, dp), rec(word1, word2, i, j + 1, m, n, dp), rec(word1, word2, i + 1, j, m, n, dp)});

        return dp[i][j] = res;
    }
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return rec(word1, word2, 0, 0, m, n, dp);
    }
};
