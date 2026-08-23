class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n - 1) return false;
        vector<vector<int>> adj(n);
        queue<pair<int, int>> q;
        vector<bool> vis(n);
        int finish = 0;

        for(auto& edge : edges){
            adj[edge[1]].push_back(edge[0]);
            adj[edge[0]].push_back(edge[1]);
        }
        q.push({0, -1});
        vis[0] = true;

        while(!q.empty()){
            
            auto [node, parent] = q.front();
            q.pop();

            for(int i : adj[node]){
                if(i == parent) continue;
                if(vis[i]) return false;
                vis[i] = true;
                q.push({i, node});
            }
            finish++;
        }

        return finish == n;
    }
};
