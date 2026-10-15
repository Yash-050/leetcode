
class Solution {
public:
    int jump(vector<int>& nums) {
        int cnt = 0, i = 0, n = nums.size();

        while (i < n - 1) {
            if (i + nums[i] >= n - 1)
                return cnt + 1;

            int mx = -1, mxidx = i;

            for (int j = i + 1;
                 j <= i + nums[i] && j < n; j++) {
                if (j + nums[j] > mx) {
                    mx = j + nums[j];
                    mxidx = j;
                }
            }

            cnt++;
            i = mxidx;
        }

        return cnt;
    }
};
