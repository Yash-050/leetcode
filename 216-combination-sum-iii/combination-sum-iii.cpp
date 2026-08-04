class Solution {
public:
    void helper(int num, int k, int target,
                vector<int>& combi,
                vector<vector<int>>& ans) {

        if (target == 0 && combi.size() == k) {
            ans.push_back(combi);
            return;
        }

        if (num > 9 || target < 0 || combi.size() > k)
            return;

        combi.push_back(num);
        helper(num + 1, k, target - num, combi, ans);
        combi.pop_back();

        helper(num + 1, k, target, combi, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> combi;

        helper(1, k, n, combi, ans);

        return ans;
    }
};