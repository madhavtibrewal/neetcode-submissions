class Solution {
public:
    void dfs(vector<vector<pair<int, int>>>& adj, vector<int>& dist, int node, int time){
        if(time >= dist[node]) return;
        dist[node] = time;
        for(auto& [nei, t] : adj[node]){
            dfs(adj, dist, nei, time + t);
        }
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n + 1);

        for(auto& time : times){
            adj[time[0]].push_back({time[1], time[2]});
        }

        vector<int> dist(n + 1, INT_MAX);
        dfs(adj, dist, k, 0);

        int res = *max_element(dist.begin() + 1, dist.end());

        return res == INT_MAX ? -1 : res;
    }
};
