class Solution {
public:
    void helper(int i, vector<int>& candidates, int target,
                vector<int>& combi, vector<vector<int>>& ans) {

        if (target == 0) {
            ans.push_back(combi);
            return;
        }

        if (i == candidates.size() || target < 0)
            return;

        // Pick
        combi.push_back(candidates[i]);
        helper(i + 1, candidates, target - candidates[i], combi, ans);
        combi.pop_back();

        // Skip all duplicates before Not Pick
        int j = i;
        while (j + 1 < candidates.size() && candidates[j] == candidates[j + 1])
            j++;

        // Not Pick
        helper(j + 1, candidates, target, combi, ans);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> combi;

        helper(0, candidates, target, combi, ans);

        return ans;
    }
};