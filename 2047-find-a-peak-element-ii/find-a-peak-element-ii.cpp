class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {//brute force 
        int m = mat.size();
        int n = mat[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                bool up = (i == 0) || (mat[i][j] > mat[i - 1][j]);
                bool down = (i == m - 1) || (mat[i][j] > mat[i + 1][j]);
                bool left = (j == 0) || (mat[i][j] > mat[i][j - 1]);
                bool right = (j == n - 1) || (mat[i][j] > mat[i][j + 1]);

                if (up && down && left && right)
                    return {i, j};
            }
        }

        return {};
    }
};