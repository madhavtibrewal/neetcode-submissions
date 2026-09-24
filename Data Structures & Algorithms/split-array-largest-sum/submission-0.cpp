class Solution {
public:
    int countSplits(vector<int>& nums, int m){
        int splits = 1;
        int currSum = 0;

        for(int n : nums){
            if(n + currSum <= m){
                currSum += n;
            }
            else{
                splits++;
                currSum = n;
            }
        }
        return splits;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(n < k) return -1;

        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int ans;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int splits = countSplits(nums, mid);

            if(splits > k){
                low = mid + 1;
            }
            else{
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};