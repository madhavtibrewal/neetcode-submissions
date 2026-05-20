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
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));
        int n = coins.size();
        for(int i = 0; i < n + 1; i++){
            dp[i][0] = 1;
        }

        for(int i = n - 1; i >= 0; i--){
            for(int j = 0; j <= amount; j++){
                int notTake = dp[i + 1][j];
                int take = 0;
                if(coins[i] <= j){
                    take = dp[i][j - coins[i]];
                }
                dp[i][j] = take + notTake;
            }
        }

        return dp[0][amount];
        //return rec(amount, coins, 0, dp);
    }
};
