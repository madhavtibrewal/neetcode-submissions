class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        int INF = 1e9;
        vector<vector<pair<int, int>>> adj(n);
        vector<vector<int>> dist(n, vector<int>(k + 2, INF));

        for(auto& flight : flights){
            int from  = flight[0], to = flight[1], price = flight[2];

            adj[from].push_back({to, price});
        }
        dist[src][0] = 0;

        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> minHeap;
        minHeap.push({0, src, -1});

        while(!minHeap.empty()){
            auto [cost, node, stops] = minHeap.top();
            minHeap.pop();
            if(node == dst) return cost;
            if(stops == k || dist[node][stops + 1] < cost) continue;
            for(auto& [nei, w] : adj[node]){
                int newCost = cost + w;
                int nextStops = stops + 1;
                if(dist[nei][nextStops + 1] > newCost){
                    dist[nei][nextStops + 1] = newCost;
                    minHeap.push({newCost, nei, nextStops});
                }
            }
        }
        return -1;

    }
};
