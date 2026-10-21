
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";

        unordered_map<char, int> mp;
        for (char c : t) {
            mp[c]++;
        }

        int i = 0, st = 0, mn = INT_MAX;
        int missing = t.size();

        for (int j = 0; j < s.size(); j++) {
            if (mp[s[j]] > 0) {
                missing--;
            }
            mp[s[j]]--;

            while (missing == 0) {
                if (j - i + 1 < mn) {
                    mn = j - i + 1;
                    st = i;
                }

                mp[s[i]]++;
                if (mp[s[i]] > 0) {
                    missing++;
                }
                i++;
            }
        }

        return mn == INT_MAX ? "" : s.substr(st, mn);
    }
};
