class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        dfs(candidates, target, path, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& path, int idx){
        if(target == 0){
            res.push_back(path);
            return;
        }

        if(target < 0 || idx >= candidates.size()) return;

        path.push_back(candidates[idx]);
        dfs(candidates, target - candidates[idx], path, idx + 1);
        path.pop_back();

        while(idx + 1 < candidates.size() && candidates[idx] == candidates[idx  + 1])
        idx++;

        dfs(candidates, target, path, idx + 1);
    }
};
