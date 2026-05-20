class Solution {
public:
    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int dfs(vector<vector<int>>& grid, int r, int c){
        int res = 0;
        if(r < grid.size() && r >= 0 && c < grid[0].size() && 
            c >= 0 && grid[r][c] == 1){
            grid[r][c] = 0;
            res = 1;
            for(auto& [x, y] : dir){
                res += dfs(grid, r + x, c + y);
            }
        }
        return res;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1)
                ans = max(ans, dfs(grid, i, j));
            }
        }
        return ans;
    }
};
