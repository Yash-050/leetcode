class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int j = 0, mx = 0, cnt = 0;
        if (k == nums.size())
            return k;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == 0)
                cnt++;

            while (cnt > k) {
                if (nums[j] == 0)
                    cnt--;

                j++;
            }

            mx = max(mx, i - j + 1);
        }
        return mx;
    }
};