class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(128, 0);
        int j = 0;
        int maxi = 0;
        for (int i = 0; i < s.size(); i++) {
            while (freq[s[i]] > 0) {
                freq[s[j]]--;
                j++;
                
            }
            freq[s[i]]++;
            maxi = max(maxi, i - j+1);
        }
        return maxi;
    }
};