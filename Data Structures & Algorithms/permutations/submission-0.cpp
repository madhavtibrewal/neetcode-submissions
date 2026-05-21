class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.empty()) return {{}};

        vector<int> temp(nums.begin() + 1, nums.end());
        vector<vector<int>> perms = permute(temp);
        vector<vector<int>> res;

        for(auto& p : perms){
            for(int i = 0; i <= p.size(); i++){
                auto p_copy = p;
                p_copy.insert(p_copy.begin() + i, nums[0]);
                res.push_back(p_copy);
            }
        }
        
        return res;
    }
};
