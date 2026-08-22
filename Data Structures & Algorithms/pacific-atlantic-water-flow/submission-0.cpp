class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        vector<vector<bool>> pac(rows, vector<bool>(cols, false));
        vector<vector<bool>> atl(rows, vector<bool>(cols, false));

        for(int j = 0; j < cols; j++){
            dfs(pac, heights, 0, j);
            dfs(atl, heights, rows - 1, j);
        }

        for(int i = 0; i < rows; i++){
            dfs(pac, heights, i, 0);
            dfs(atl, heights, i, cols - 1);
        }
        vector<vector<int>> res;
        for(int r = 0; r < rows; r++){
            for(int c = 0; c < cols; c++){
                if(pac[r][c] && atl[r][c])
                    res.push_back({r, c});
            }
        }
        return res;
    }

    void dfs(vector<vector<bool>>& ocean, vector<vector<int>>& heights, int i, int j){
        ocean[i][j] = true;
        for(auto [dr, dc] : dir){
            int nr = i + dr;
            int nc = j + dc;

            if(nr >= 0 && nr < heights.size() && nc >= 0 && nc < heights[0].size() && !ocean[nr][nc] && heights[nr][nc] >= heights[i][j]){
                dfs(ocean, heights, nr, nc);
            }
        }
    }
};
