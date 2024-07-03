class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> moves(m, vector<int>(n));
        for(int i = 0; i < n; i++){
            moves[0][i] = 1;
        }
        for(int i = 0; i < m; i++){
            moves[i][0] = 1;
        }

        for(int i = 1; i < m; i++){
            for(int j = 1; j < n; j++){
                moves[i][j] = moves[i-1][j] + moves[i][j-1];
            }
        }

        int ans = moves[m-1][n-1];
        return ans;
    }
};