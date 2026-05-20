class Solution {
public:
    bool dfs(vector<int>& nums, int i){
        if(i == nums.size() - 1) return true;

        int end = min((int)nums.size() - 1, i + nums[i]);

        for(int j = i + 1; j <= end; j++){
            if(dfs(nums, j)){
                return true;
            }
        }

        return false;
    }
    bool canJump(vector<int>& nums) {
        //return dfs(nums, 0);
        int n = nums.size();

        vector<bool> dp(n, false);

        dp[n - 1] = true;

        for(int i = n - 2; i >= 0; i--){

            int end = min(n - 1, i + nums[i]);

            for(int j = i + 1; j <= end; j++){
                if(dp[j]){
                    dp[i] = true;
                }
            }
        }
        return dp[0];
    }
};
