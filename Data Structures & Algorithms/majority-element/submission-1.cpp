class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int n = nums.size();
        int freq = 0;

        for(int i : nums){
            if(freq == 0) maj = i;
            freq += (maj == i) ? 1 : -1;
        }

        return maj;
    }
};