class Solution {
public:
    int rec(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(i < 0){
            return target == 0 ? 1 : 0;
        }
        if(target < 0) return 0;
        if(dp[i][target] != -1) return dp[i][target];
        int notTake = rec(nums, target, i - 1, dp);
        int take = rec(nums, target - nums[i], i - 1, dp);

        return dp[i][target] = take + notTake;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;

        for(int i : nums) total += i;

        if (total < abs(target) || (total + target) % 2 != 0) {
            return 0;
        }

        int newTarget = (total + target) / 2;
        vector<vector<int>> dp(n, vector<int>(newTarget + 1, -1));
        return rec(nums, newTarget, n - 1, dp);
    }
};
