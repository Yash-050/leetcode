class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long k = 1LL * k1 + k2;

        vector<int> diff(n);
        int maxi = 0;
        long long total = 0;

        for (int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            maxi = max(maxi, diff[i]);
            total += diff[i];
        }

        if (total <= k) return 0;

        int low = 0, high = maxi;

        while (low < high) {
            int mid = low + (high - low) / 2;
            long long need = 0;

            for (int d : diff) {
                if (d > mid)
                    need += d - mid;
            }

            if (need <= k)
                high = mid;
            else
                low = mid + 1;
        }

        int level = low;
        long long need = 0;
        long long ans = 0;

        for (int d : diff) {
            if (d > level)
                need += d - level;

            int x = min(d, level);
            ans += 1LL * x * x;
        }

        long long remaining = k - need;

        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};