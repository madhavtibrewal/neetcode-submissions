class Solution {
public:
    int rec(vector<int>& nums, int i, int j, vector<vector<int>>& dp){
        if(j >= nums.size()) return 0;
        if(dp[i + 1][j] != -1) return dp[i + 1][j];

        int notTake = rec(nums, i, j + 1, dp);
        int take = 0;
        if(i == -1 || nums[i] < nums[j]){
            take = 1 + rec(nums, j, j + 1, dp);
        }

        return dp[i + 1][j] = max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) return 0;
        if(n == 1) return 1;

        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return rec(nums, -1, 0, dp);
    }
};
