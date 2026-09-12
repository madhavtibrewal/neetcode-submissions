class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int res = 0, curSum = 0;
        unordered_map<int, int> prefixSum;
        prefixSum[0] = 1;

        for(int num : nums){
            curSum += num;
            int diff = curSum - k;
            res += prefixSum[diff];
            prefixSum[curSum]++;
        }

        return res;
    }
};