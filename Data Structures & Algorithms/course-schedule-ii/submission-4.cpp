class Solution {
public:
    unordered_map<int, vector<int>> adjMap;
    vector<int> vis;
    vector<int> ans;

    bool dfs(int c){
        if(vis[c] == 1) return false;

        if(vis[c] == 2) return true;

        vis[c] = 1;

        for(auto& course : adjMap[c]){
            if(!dfs(course)){
                return false;
            }
        }

        vis[c] = 2;
        ans.push_back(c);
        return true;

    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // vector<int> indegree(numCourses, 0);
        // for(auto& edge : prerequisites){
        //     indegree[edge[0]]++;
        // }

        vis.resize(numCourses, 0);

        for(auto& edge : prerequisites){
            adjMap[edge[1]].push_back(edge[0]);
        }

        // queue<int> cq;

        // for(int i = 0; i < numCourses; i++){
        //     if(indegree[i] == 0){
        //         cq.push(i);
        //     }
        // }

        // int processed = 0;

        // while(!cq.empty()){
        //     for(auto& i : adjMap[cq.front()]){
        //         indegree[i]--;
        //         if(indegree[i] == 0) cq.push(i);
        //     }
        //     cq.pop();
        //     processed++;
        // }

        for(int i = 0 ; i < numCourses; i++){
            if(!dfs(i)){
                return {};
            }
        }

        //return processed == numCourses;
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
