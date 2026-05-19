class Solution {
public:
    vector<vector<int>> res;
    void backtrack(vector<int>& nums, int target, vector<int>& curr, int i){
        if(target == 0){
            res.push_back(curr);
            return;
        }

        if(i >= nums.size()) return;

        if(target >= nums[i]){
            curr.push_back(nums[i]);
            backtrack(nums, target - nums[i], curr, i);
            curr.pop_back();
        }
        backtrack(nums, target, curr, i + 1);
    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(nums, target, curr, 0);
        return res;
    }
};