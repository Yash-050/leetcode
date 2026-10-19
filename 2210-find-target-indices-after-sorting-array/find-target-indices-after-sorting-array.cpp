class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int l = 0, r = 0;

        for (int i : nums) {
            if (i < target) {
                l++;
            } else if (i == target) {
                r++;
            }
        }


        vector<int> ans;

        for (int i = l; i < l + r; i++) {
            ans.push_back(i);
        }

        return ans;
    }
};