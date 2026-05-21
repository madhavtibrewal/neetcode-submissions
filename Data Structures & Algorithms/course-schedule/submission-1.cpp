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
        vector<int> indegree(numCourses, 0);
        for(auto& edge : prerequisites){
            indegree[edge[1]]++;
        }

        for(auto& edge : prerequisites){
            preMap[edge[0]].push_back(edge[1]);
        }
        queue<int> q;

        for(int c = 0; c < numCourses; c++){
            if(indegree[c] == 0) q.push(c);
        }

        int finish = 0;
        while(!q.empty()){
            for(auto& pre : preMap[q.front()]){
                indegree[pre]--;
                if(indegree[pre] == 0) q.push(pre);
            }
            q.pop();
            finish++;
        }

        return finish == numCourses;
    }
};
