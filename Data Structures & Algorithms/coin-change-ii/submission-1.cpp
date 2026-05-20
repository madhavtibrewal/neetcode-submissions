class Solution {
public:
    int rec(int amount, vector<int>& coins, int i, vector<vector<int>>& dp){
        if(amount == 0){
            return 1;
        }
        if(i == coins.size()){
            return 0;
        }
        if(dp[i][amount] != -1) return dp[i][amount];
        int take = 0;
        if(coins[i] <= amount){
            take = rec(amount - coins[i], coins, i, dp);
        }
        int notTake = rec(amount, coins, i + 1, dp);

        return dp[i][amount] = take + notTake;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1, -1));
        return rec(amount, coins, 0, dp);
    }
};
