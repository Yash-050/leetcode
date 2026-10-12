class Solution {
public:
    vector<pair<int,int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

    void dfs(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || j < 0 || i >= n || j >= m || grid[i][j] != '1') {
            return;
        }

        grid[i][j] = '$';  

        for (pair<int,int>& d : dir) {
            int ni = i + d.first;
            int nj = j + d.second;

            dfs(grid, ni, nj);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    dfs(grid, i, j);
                    cnt++;
                }
            }
        }

        return cnt;
    }
};