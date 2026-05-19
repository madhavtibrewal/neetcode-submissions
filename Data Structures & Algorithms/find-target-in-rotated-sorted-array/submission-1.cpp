class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while(l <= r){
            int mid = l + ((r - l) / 2);

            if(target == nums[mid]) return mid;

            if(nums[l] <= nums[mid]){ // left portion 
                if(target > nums[mid] || target < nums[l]){
                    l = mid + 1;
                }
                else{
                    r = mid - 1;
                }
            }
            else{
                if(target < nums[mid] || target > nums[r]){
                    r = mid - 1;
                }
                else{
                    l = mid + 1;
                }
            }
            /*
            4 5 6 7 0 1
            mid = 6
            target = 7
            if target > mid go right
            l = mid + 1;

            mid = 0;

            if target > mid 
            */
        }
        return -1;
    }
};
