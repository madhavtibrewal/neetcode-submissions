class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> lMax(n);
        vector<int> rMax(n);

        lMax[0] = nums[0];
        rMax[n - 1] = nums[n - 1];

        for(int i = 1; i < n; i++){
            if(i % k == 0){
                lMax[i] = nums[i];
            }
            else{
                lMax[i] = max(lMax[i - 1], nums[i]);
            }
            int rIndex = n - i - 1; 
            if(rIndex % k == 0){
                rMax[rIndex] = nums[rIndex];
            }
            else{
                rMax[rIndex] = max(rMax[rIndex + 1], nums[rIndex]);
            }
        }
        vector<int> output(n - k + 1);

        for(int i = 0; i < n - k + 1; i++){
            output[i] = max(lMax[i + k - 1], rMax[i]);
        }

        return output;
    }
};
