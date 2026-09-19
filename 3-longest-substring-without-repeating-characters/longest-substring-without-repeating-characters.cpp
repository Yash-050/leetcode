class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> h(256, -1);
        int l = 0, r = 0, mx = 0;
        while (r < s.size()) {
            if (h[s[r]] != -1) {
                if (h[s[r]] >= l) {
                    l = h[s[r]] + 1;
                }
            }
            mx = max(mx,r-l+1);
            h[s[r]] = r;
            r++;
        }
        return mx;
    }
};