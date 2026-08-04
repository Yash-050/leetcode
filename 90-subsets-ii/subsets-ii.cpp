class Solution {
public:
    void backtrack(int index, vector<int>& nums, vector<int>& current,
                   vector<vector<int>>& ans) {

        if (index == nums.size()) {
            ans.push_back(current);
            return;
        }

        // Include
        current.push_back(nums[index]);
        backtrack(index + 1, nums, current, ans);
        current.pop_back();

        // Skip all duplicates
        int i = index;
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;

        // Exclude
        backtrack(i + 1, nums, current, ans);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {

        sort(nums.begin(), nums.end());   // <-- Missing

        vector<vector<int>> ans;
        vector<int> current;

        backtrack(0, nums, current, ans);

        return ans;
    }
};