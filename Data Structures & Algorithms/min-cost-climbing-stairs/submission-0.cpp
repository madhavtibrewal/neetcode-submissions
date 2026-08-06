class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n + 1, -1);
        return recursion(cost, dp, n);
    }
private:
    int recursion(vector<int>& cost, vector<int>& dp, int n){
        if(n < 2) return cost[n];
        if(dp[n] != -1) return dp[n];
        return dp[n] = ((n == cost.size()) ? 0 : cost[n]) + min(recursion(cost, dp, n - 1), recursion(cost, dp, n - 2));
    }
};
