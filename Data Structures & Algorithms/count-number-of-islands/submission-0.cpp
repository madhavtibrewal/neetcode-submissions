class Solution {
public:
    vector<pair<int,int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    void dfs(vector<vector<char>>& grid, int r, int c){
        if(r < 0 || c < 0 || r >= grid.size() || c >= grid[0].size() || grid[r][c] == '0'){
            return;
        }
        grid[r][c] = '0';
        for(auto& [x, y] : directions){
            dfs(grid, r + x, c + y);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == '1'){
                    dfs(grid, i, j);
                    count++;
                }
            }
        }

        return count;
    }
};
