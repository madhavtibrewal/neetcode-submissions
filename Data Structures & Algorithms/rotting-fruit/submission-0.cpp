class Solution {
public:
    vector<pair<int, int>> dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int freshCount = 0;
        int minutes = 0;

        queue<pair<int, int>> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 2){
                    q.push({i , j});
                }
                else if(grid[i][j] == 1){
                    freshCount++;
                }
            }
        }

        if(freshCount == 0) return 0;

        while(!q.empty() && freshCount > 0){
            int size = q.size();
            for(int k = 0; k < size; k++){
                auto [i, j] = q.front();
                q.pop();

                for(auto &[dx, dy] : dirs){
                    int x = dx + i;
                    int y = dy + j;

                    if(x < 0 || x >= n || y < 0 || y >= m || grid[x][y] != 1 ){
                        continue;
                    }

                    grid[x][y] = 2;
                    freshCount--;
                    q.push({x, y});
                } 
            }
            minutes++; 
        }

        return freshCount == 0 ? minutes : -1;
    }
};
