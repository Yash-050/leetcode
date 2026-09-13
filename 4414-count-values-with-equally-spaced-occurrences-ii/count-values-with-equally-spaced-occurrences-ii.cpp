class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]].push_back(i);
        }

        int cnt = 0;

        for (auto it : mp) {
            int n = it.second.size();

            if (n <= 2)
                continue;

            int val = abs(it.second[1] - it.second[0]);
            bool ans = true;

            for (int i = 2; i < n; i++) {
                if (abs(it.second[i] - it.second[i - 1]) != val) {
                    ans = false;
                    break;
                }
            }

            if (ans)
                cnt++;
        }

        return cnt;
    }
};