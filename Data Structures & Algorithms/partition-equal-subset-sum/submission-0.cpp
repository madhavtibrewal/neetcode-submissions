class Solution {
public:
    bool rec(vector<int>& nums, int i, int k, vector<vector<int>>& dp){
        if(i == 0){
            if(nums[i] == k) return true;
            else return false;
        }
        if(k < 0) return false;
        
        if(dp[i][k] != -1) return dp[i][k];
        bool notTake = rec(nums, i - 1, k, dp);
        bool take = rec(nums, i - 1, k - nums[i], dp);

        return dp[i][k] = notTake || take;
    }
    bool canPartition(vector<int>& nums) {
        int totalSum = 0;
        int n  = nums.size();

        for(int i : nums) totalSum += i;

        if(totalSum % 2 != 0) return false;

        vector<vector<int>> dp(n, vector<int>(totalSum/2 + 1, -1));

        return rec(nums, n - 1, totalSum / 2, dp);
    }
};
