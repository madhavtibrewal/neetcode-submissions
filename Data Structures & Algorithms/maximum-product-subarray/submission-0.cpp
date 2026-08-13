class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curMin = 1, curMax = 1;

        for(int n : nums){
            int temp = curMax;
            curMax = max({curMax * n, curMin * n, n});
            curMin = min({temp * n, curMin * n, n});
            res = max(curMax, res);
        }

        return res;
    }
};
