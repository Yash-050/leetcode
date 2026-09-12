class Solution {
public:
    int mainidea(vector<int>&h){
        int n =  h.size();
        vector<int>nse(n),pse(n);
                stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && h[st.top()] >= h[i])
                st.pop();

            pse[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }

        while (!st.empty())
            st.pop();

        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && h[st.top()] >= h[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {
            ans = max(ans, h[i] * (nse[i] - pse[i] - 1));
        }

        return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int>h(n, 0);int ans = 0 ;
        for(int i =0 ;i<m;i++){
            for(int j = 0;j<n;j++){
                if(matrix[i][j]=='1')h[j]++;//increasing a value if the 1
                else h[j] = 0 ;
            }
            ans = max(ans , mainidea(h));
        }
        return ans ;
    }
};