class Solution {
public:
    string frequencySort(string s) {
        vector<int> freq(128, 0);

        // Count frequencies
        for (char ch : s) {
            freq[ch]++;
        }

        vector<pair<int, char>> v;

        // Store (frequency, character)
        for (int i = 0; i < 128; i++) {
            if (freq[i] > 0) {
                v.push_back({freq[i], (char)i});
            }
        }

        // Sort by frequency in descending order
        sort(v.begin(), v.end(), greater<pair<int, char>>());

        string ans = "";

        for (auto i : v) {
            for (int j = 0; j < i.first; j++) {
                ans.push_back(i.second);
            }
        }

        return ans;
    }
};