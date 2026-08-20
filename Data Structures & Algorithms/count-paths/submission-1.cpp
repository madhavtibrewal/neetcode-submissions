class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> prev(n + 1, 0);

        for(int i = m - 1; i >= 0; i--){
            vector<int> cur(n + 1, 0);
            for(int j = n - 1; j >= 0; j--){
                if(j == n - 1 && i == m - 1) cur[n - 1] = 1;
                cur[j] += prev[j] + cur[j + 1]; 
            }
            prev = cur;
        }
        return prev[0];
    }
};
