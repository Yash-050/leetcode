class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;

        while (i < j) {
            if (s[i] != s[j])
                return false;
            i++;
            j--;
        }

        return true;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int cnt = 0;

        for (int i = 0; i < n;) {

            bool found = false;

            if (i + k <= n) {
                string t = s.substr(i, k);
                if (isPalindrome(t)) {
                    cnt++;
                    i += k;
                    found = true;
                }
            }

            if (!found && i + k + 1 <= n) {
                string t = s.substr(i, k + 1);
                if (isPalindrome(t)) {
                    cnt++;
                    i += k + 1;
                    found = true;
                }
            }

            if (!found)
                i++;
        }

        return cnt;
    }

    
};