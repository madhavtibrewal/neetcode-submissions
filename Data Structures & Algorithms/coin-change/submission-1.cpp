class Solution {
public:
    int rec(vector<int>& coins, int amount, int i){

        if(i == 0){
            if(amount % coins[i] == 0){
                return amount / coins[i];
            }
            else{
                return 1e9;
            }
        }

        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + rec(coins, amount - coins[i], i);
        }
        int notTake = rec(coins, amount, i - 1);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        //int ans = rec(coins, amount, coins.size() -1);
        //return (ans >= 1e9) ? -1 : ans;

        int n = coins.size();

        vector<vector<int>> dp(coins.size(), vector<int>(amount + 1));
        for(int i = 0; i <= amount; i++){
            if(i % coins[0] == 0)
                dp[0][i] = i / coins[0];
            else
                dp[0][i] = 1e9;
        }

        for(int i = 1; i < n; i++){
            for(int j = 1; j <= amount; j++){
                int take = 1e9;
                if(coins[i] <= j){
                    take = 1 + dp[i][j - coins[i]];
                }
                int notTake = dp[i - 1][j];
                dp[i][j] = min(take, notTake);
            }
        }

        return dp[n-1][amount] == 1e9 ? -1 : dp[n-1][amount];
    }
};
