class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;

        for(auto& edge : edges){
            int p1 = find(edge[0], parent);
            int p2 = find(edge[1], parent);

            if(p1 == p2) return edge;

            parent[p1] = p2;
        }

        return {};
        
    }

    int find(int n, vector<int>& parent){
        if(parent[n] != n){
            parent[n] = find(parent[n], parent);
        }
        return parent[n];
    }
};
