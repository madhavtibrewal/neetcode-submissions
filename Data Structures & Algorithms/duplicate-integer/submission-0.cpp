class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        set<int> ans;

        for(int i : nums){
            ans.insert(i);
        }

        return ans.size() != nums.size();

    }
};