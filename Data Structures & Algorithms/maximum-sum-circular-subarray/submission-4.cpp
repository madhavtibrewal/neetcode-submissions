class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMin = 0, globalMin = nums[0];
        int currMax = 0, globalMax = nums[0];
        int total = 0;

        for(int x : nums){
            total += x;

            currMax = max(x, currMax + x);
            globalMax = max(currMax, globalMax);

            currMin = min(x, currMin + x);
            globalMin = min(currMin, globalMin);
        }

        if(globalMax < 0) return globalMax;

        return max(globalMax, total - globalMin);
    }
};