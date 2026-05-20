class Solution {
public:
    int rec(vector<int>& nums, int n){
        vector<int>dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i < n; i++){
            dp[i]  = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        vector<int> nums1(nums.begin(), nums.end() -1);
        vector<int> nums2(nums.begin() + 1, nums.end());
        return max(rec(nums1, n - 1), rec(nums2, n - 1));
    }
};
