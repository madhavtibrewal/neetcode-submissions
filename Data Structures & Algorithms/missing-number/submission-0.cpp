class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int sum2 = (n * (n + 1)) / 2;
        for(int i : nums) sum += i;

        return sum2 - sum;
    }
};
