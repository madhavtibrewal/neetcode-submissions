class Solution {
public:
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> vis;

    bool dfs(int c){
        if(vis.count(c)) return false;

        if(preMap[c].empty()) return true;

        vis.insert(c);

        for(auto& pre : preMap[c]){
            if(!dfs(pre)) return false;
        }
        vis.erase(c);
        preMap[c].clear();
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& edge : prerequisites){
            preMap[edge[0]].push_back(edge[1]);
        }

        for(int c = 0; c < numCourses; c++){
            if(!dfs(c)) return false;
        }

        return true;
    }
};
