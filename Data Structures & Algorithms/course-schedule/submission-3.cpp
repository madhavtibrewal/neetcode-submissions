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
        vector<int> indegree(numCourses, 0);

        for(auto& edge : prerequisites){
            indegree[edge[0]]++;
        }

        for(auto& edge : prerequisites){
            adjMap[edge[1]].push_back(edge[0]);
        }

        queue<int> cq;

        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                cq.push(i);
            }
        }

        int processed = 0;

        while(!cq.empty()){
            for(auto& i : adjMap[cq.front()]){
                indegree[i]--;
                if(indegree[i] == 0) cq.push(i);
            }
            cq.pop();
            processed++;
        }

        // for(int i = 0 ; i < numCourses; i++){
        //     if(!dfs(i)){
        //         return false;
        //     }
        // }

        return processed == numCourses;
    }
};
