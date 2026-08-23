class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        queue<int> q;
        vector<int> res;

        for(auto& edge : prerequisites){
            indegree[edge[0]]++;
            adj[edge[1]].push_back(edge[0]);
        }
        for(int i = 0; i  < numCourses; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            
            int curr = q.front();
            q.pop();
            res.push_back(curr);

            for(int i : adj[curr]){
                indegree[i]--;
                if(indegree[i] == 0){
                    q.push(i);
                }
            }
        }

        return res.size() != numCourses ? vector<int>{} : res;
    }
};
