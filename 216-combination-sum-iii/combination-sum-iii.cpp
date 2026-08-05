class Solution {
public:
    void help(int idx, vector<int>& curr, vector<vector<int>>& ans,
              int k, int target) {

        if (target < 0)
            return;

        if (curr.size() == k) {
            if (target == 0)
                ans.push_back(curr);
            return;
        }
        //new cases 
        if (idx > 9)
            return;

        if (curr.size() + (10 - idx) < k)//checkinf for if we can still reach it 
            return;

        // Pick
        curr.push_back(idx);
        help(idx + 1, curr, ans, k, target - idx);
        curr.pop_back();

        // Not Pick
        help(idx + 1, curr, ans, k, target);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        vector<vector<int>> ans;
        vector<int> curr;

        help(1, curr, ans, k, n);

        return ans;
    }
};