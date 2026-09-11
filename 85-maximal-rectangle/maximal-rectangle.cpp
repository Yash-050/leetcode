class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int ans = 0;

        for (int top = 0; top < m; top++) {
            vector<int> valid(n, 1);

            for (int bottom = top; bottom < m; bottom++) {

                for (int j = 0; j < n; j++) {
                    if (matrix[bottom][j] == '0')
                        valid[j] = 0;
                }

                int width = 0;

                for (int j = 0; j < n; j++) {
                    if (valid[j]) {
                        width++;
                        ans = max(ans, width * (bottom - top + 1));
                    } else {
                        width = 0;
                    }
                }
            }
        }

        return ans;
    }
};