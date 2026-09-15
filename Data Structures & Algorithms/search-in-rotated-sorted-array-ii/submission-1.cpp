class Solution {

    /*
     [3,4,4,5,6,1,2,2]
     l = 0, r = 7
     m = 3 num = 5 - > target <  arr[m] and also arr[m] > arr[r] and arr[m] > arr[l]
     if(arr[r] > nums)
     if(target <= arr[r])-------1 < 2 that means l = m + 1
     if(target > arr[r])

     5 6 1 2 3 4 -- so to find 6....target > mid then check if target is greater than arr[r], yes then we need to check on the left of mid...
     if target < mid...then check if mid
     4 5 6 1 2 3
    */
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;

        while(l <= r){
            int m = l + (r - l) / 2;

            if(nums[m] == target) return true;

            if(nums[l] < nums[m]){
                if(nums[m] > target && target >= nums[l]){
                    r = m - 1;
                }
                else {
                    l = m + 1;
                }
            }

            else if(nums[l] > nums[m]){
                if(target > nums[m] && target <= nums[r]){
                    l = m + 1;
                }
                else{
                    r = m - 1;
                }
            }
            else{
                l++;
            }
        }

        return false;
    }
};