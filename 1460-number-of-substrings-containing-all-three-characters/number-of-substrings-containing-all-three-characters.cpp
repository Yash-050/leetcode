class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        unordered_map<char, int> mp;

        mp['a'] = 0;
        mp['b'] = 0;
        mp['c'] = 0;

        int j = 0;
        int sz = 3;

        for (int i = 0; i < s.size(); i++) {
            mp[s[i]]++;

            if (mp[s[i]] == 1) {
                sz--;
            }

            while (sz == 0) {
                cnt += s.size() - i;

                mp[s[j]]--;

                if (mp[s[j]] == 0) {
                    sz++;
                }

                j++;
            }
        }

        return cnt;
    }
};