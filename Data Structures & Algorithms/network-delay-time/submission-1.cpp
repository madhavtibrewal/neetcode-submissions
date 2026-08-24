class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        for(int i = 0; i < n - 1; i++){
            for(auto& time : times){
                int u = time[0], v = time[1], w = time[2];
                if(dist[u] != INT_MAX && dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                }
            }
        }

        int res = *max_element(dist.begin() + 1, dist.end());
        return res == INT_MAX ? -1 : res;
    }
};
