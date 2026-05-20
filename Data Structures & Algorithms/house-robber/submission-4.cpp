class Solution {
public:
    int rec(vector<int>& nums, int i, vector<int>& dp){
        if(i < 0) return 0;
        if(dp[i] != -1) return dp[i];
        int notTake = rec(nums, i - 1, dp);
        int take = nums[i] + rec(nums, i - 2, dp);

        return dp[i] = max(take, notTake);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];

        vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = max(nums[1], nums[0]);

        for(int i = 2; i < n; i++){
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
        //return rec(nums, n - 1, dp);
    }
};
