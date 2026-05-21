class Solution {
public:
    int dfs(vector<int>& nums, int i, int j){
        if(j < 0) return 0;

        int notTake = dfs(nums, i, j - 1);
        int take = 0;
        if(i == nums.size() || (nums[j] < nums[i])){
            take = 1 + dfs(nums, j, j - 1);
        }

        return max(take, notTake);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //return dfs(nums, n, n - 1);

        vector<int> dp(n, 1);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[j] < nums[i]){
                    dp[i] = max(dp[i], 1 + dp[j]);
                }
            }
        }

        return *max_element(dp.begin(), dp.end());
    }
};

