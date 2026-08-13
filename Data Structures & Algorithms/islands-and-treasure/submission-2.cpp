class Solution {
private:
    vector<pair<int,int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 0)
                    q.push({i, j});
            }
        }

        while(!q.empty()){
            auto [i, j] = q.front();
            q.pop();

            for(auto& [dx, dy] : dir){
                int x = dx + i;
                int y = dy + j;

                if(x < 0 || x >= n  || y < 0 || y >= m || grid[x][y] != 2147483647){
                    continue;
                }

                grid[x][y] = grid[i][j] + 1;
                q.push({x, y});
            }
        }
    }
};
