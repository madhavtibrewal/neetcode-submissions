class Solution {
public:
    int rec(vector<int>& prices, int i, bool isBuying, vector<vector<int>>& dp){
        if(i >= prices.size()) return 0;
        if(dp[i][isBuying] != -1) return dp[i][isBuying];
        int profit = 0;
        if(isBuying){
            int buy = rec(prices, i + 1, !isBuying, dp) - prices[i];
            int cooldown = rec(prices, i + 1, isBuying, dp);
            profit  = max(buy, cooldown);
        }
        else{
            int sell = rec(prices, i + 2, !isBuying, dp) + prices[i];
            int cooldown = rec(prices, i + 1, isBuying, dp);
            profit = max(sell, cooldown);
        }

        return dp[i][isBuying] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return rec(prices, 0, true, dp);
    }
};
