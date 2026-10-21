
class Solution {
public:
    int characterReplacement(string s, int k) {
        int mxlen = 0;
        vector<int> freq(26, 0);
        int maxf = 0;
        int j = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'A']++;
            maxf = max(maxf, freq[s[i] - 'A']);

            while ((i - j + 1) - maxf > k) {
                freq[s[j] - 'A']--;
                j++;
            }

            mxlen = max(mxlen, i - j + 1);
        }

        return mxlen;
    }
};
