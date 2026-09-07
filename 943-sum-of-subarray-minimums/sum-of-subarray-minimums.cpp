class Solution {
public:
    const int MOD = 1000000007;

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> nse(n), pse(n);
        stack<int> st;

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();

            st.push(i);
        }

        while (!st.empty())
            st.pop();

        // Previous Smaller Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - pse[i];
            long long right = nse[i] - i;

            long long contribution =
                left * right * arr[i];

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};