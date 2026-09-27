
class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> freq(128, 0);

        for (char c : s) {
            freq[c]++;
        }

        int ans = 0;
        bool oddFound = false;

        for (int count : freq) {
            ans += (count / 2) * 2;

            if (count % 2 == 1) {
                oddFound = true;
            }
        }

        if (oddFound) {
            ans++;
        }

        return ans;
    }
};
