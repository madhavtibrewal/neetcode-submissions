class Solution {
public:
    // -1 0 2 4 6 8
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int ans = 0;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] >= target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }

        return l;
    }
};