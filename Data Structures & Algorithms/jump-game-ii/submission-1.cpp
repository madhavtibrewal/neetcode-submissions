class Solution {
public:
    int dfs(vector<int>& nums, int i){
        int n = nums.size();
        if(n - 1 == i) return 0;

        int end = min(n - 1, i + nums[i]);
        int res = INT_MAX;

        for(int j = i + 1; j <= end; j++){
            res = min(res, 1 + dfs(nums, j));
        }

        return res;
    }
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 1e9);

        dp[n - 1] = 0;

        for(int i = n - 2; i >= 0; i--){
            int end = min(n - 1, i + nums[i]);
            int res = 1e9;
            for(int j = i + 1; j <= end; j++){
                res = min(res, 1 + dp[j]);
            }
            dp[i] = res;
        }
     return dp[0];   
    }
};
