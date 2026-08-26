class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj = nums[0];
        int n = nums.size();
        int freq = 1;

        for(int i = 1; i < n; i++){
            if(freq == 0) maj = nums[i];

            if(maj == nums[i]) freq++;
            else{
                freq--;
            }
        }

        return maj;
    }
};