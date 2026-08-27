class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, r = 0;
        int n = nums.size();
        int res = n + 1;
        int sum = 0;

        for(int r = 0; r < n; r++){
            sum += nums[r];
            while(sum >= target){
                res = min(res, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }

        return res > n ? 0 : res;
    }
};