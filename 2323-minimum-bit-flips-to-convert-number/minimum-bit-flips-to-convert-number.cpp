class Solution {
public:
    string conversion(int n) {
        string ans = "";
        for (int i = 31; i >= 0; i--) {
            ans += ((n >> i) & 1);
        }
        // reverse(ans.begin(), ans.end());
        return ans;
    }
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        string s = conversion(start);
        string g = conversion(goal);
        
        for (int i = s.size() - 1; i >= 0; i--) {
            if (s[i] != g[i])
                cnt++;
        }
        return cnt;
    }
};