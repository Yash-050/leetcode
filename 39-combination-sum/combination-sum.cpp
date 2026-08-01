class Solution {
public:
    void helper(int i, vector<int>& candidates, int target, vector<int>& combi,
                vector<vector<int>> &ans) {//most understanible one 
                    if(i==candidates.size() || target<0){
                        return ;
                    }
                    if(target == 0 ){
                        ans.push_back(combi);
                        return;
                    }
                    combi.push_back(candidates[i]);
                    helper(i+1, candidates,  target-candidates[i], combi, ans);//every time is target is getting subtracted 
                    helper(i, candidates,  target-candidates[i], combi, ans);
                    combi.pop_back();
                    helper(i+1, candidates,  target, combi, ans);
                }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> combi;
        vector<vector<int>> ans;
        helper( 0 ,candidates, target,combi ,ans);
        set<vector<int>> s(ans.begin(),ans.end());
        ans.clear();
        for(auto i : s){
            ans.push_back(i);
        }
        return ans;
    }
};