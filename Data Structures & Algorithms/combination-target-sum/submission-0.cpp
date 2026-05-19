class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        // dp[i] will store all unique combinations that sum to i
        vector<vector<vector<int>>> dp(target + 1);
        
        // Base case: to make a sum of 0, we use an empty combination
        dp[0] = {{}};
        
        // Outer loop over nums ensures we maintain a strict order,
        // which naturally prevents duplicate combinations like [2, 5] and [5, 2]
        for (int num : nums) {
            for (int i = num; i <= target; i++) {
                // If the sub-problem has valid combinations
                for (auto comb : dp[i - num]) {
                    comb.push_back(num);
                    dp[i].push_back(comb);
                }
            }
        }
        
        return dp[target];
    }
};