class Solution {
public:
    int findParent(int node, vector<int>& parent){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node], parent);
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parent(n);

        for(int i = 0; i < n; i++){
            parent[i] = i;
        }

        int components = n; 

        for(auto& edge : edges){
            int rootX = findParent(edge[0], parent);
            int rootY = findParent(edge[1], parent);

            if(rootX != rootY){
                parent[rootX] = parent[rootY];
                components--;
            }
        }

        return components;
    }
};
