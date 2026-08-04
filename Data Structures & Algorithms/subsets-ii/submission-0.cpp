class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> subset;
        sort(nums.begin(), nums.end());
        backtrack(nums, 0, subset, res);

        return res;
    }
private:
    void backtrack(vector<int>& nums, int i, vector<int>& subset, vector<vector<int>>& res){
        if(i == nums.size()){
            res.push_back(subset);
            return;
        }

        subset.push_back(nums[i]);
        backtrack(nums, i + 1, subset, res);
        subset.pop_back();
        while(i + 1 < nums.size() && nums[i] == nums[i + 1]){
            i++;
        }

        backtrack(nums, i + 1, subset, res);
    }
};
