
class Solution {
public:
    int sumCounts(vector<int>& nums) {
        vector<vector<int>> vc;
        int n = nums.size();

        // Step 1: Create all subarrays
        for (int i = 0; i < n; i++) {
            vector<int> temp;

            for (int j = i; j < n; j++) {
                temp.push_back(nums[j]);
                vc.push_back(temp);
            }
        }

        int ans = 0;

        for (auto &subarray : vc) {
            unordered_set<int> st(subarray.begin(), subarray.end());

            int distinct = st.size();
            ans += distinct * distinct;
        }

        return ans;
    }
};
