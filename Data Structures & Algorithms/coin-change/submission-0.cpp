class Solution {
public:
    int rec(vector<int>& coins, int amount, int i){
        if(amount == 0) return 0;
        if(i < 0) return 1e9;

        int take = 1e9;
        if(coins[i] <= amount){
            take = 1 + rec(coins, amount - coins[i], i);
        }
        int notTake = rec(coins, amount, i - 1);

        return min(take, notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = rec(coins, amount, coins.size() -1);
        return (ans >= 1e9) ? -1 : ans;
    }
};
