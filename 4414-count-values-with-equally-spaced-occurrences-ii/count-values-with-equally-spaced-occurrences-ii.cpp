 class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }
        int cnt = 0;
        for (auto it : mp) {
            int n = it.second.size();bool ans = true;
            if(n<=2)continue;   
            int val = abs(it.second[0]-it.second[1]);
            for (int i = 1; i < n; i++) {
                if(i+1<n&&abs(it.second[i]-it.second[i+1])!=val)ans = false;
            }
            if(ans)cnt++;
        }
        return cnt;
    }
};