class Solution {
public:
    unordered_map<int, vector<int>> adjMap;
    unordered_set<int> vis;

    bool dfs(int c){
        if(vis.count(c)) return false;

        if(adjMap.empty()) return true;

        vis.insert(c);

        for(auto& course : adjMap[c]){
            if(!dfs(course)){
                return false;
            }
        }

        vis.erase(c);
        adjMap[c].clear();
        return true;

    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto& edge : prerequisites){
            adjMap[edge[1]].push_back(edge[0]);
        }

        for(int i = 0 ; i < numCourses; i++){
            if(!dfs(i)){
                return false;
            }
        }

        return true;
    }
};
