class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

    void getallpart(int idx, string &s, vector<string> &temp,
                    vector<vector<string>> &ans) {

        // Base case
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        // Try every possible substring starting from idx
        for (int i = idx; i < s.size(); i++) {

            // Only proceed if s[idx...i] is a palindrome
            if (isPalindrome(s, idx, i)) {

                string part = s.substr(idx, i - idx + 1);

                // Choose
                temp.push_back(part);

                // Explore
                getallpart(i + 1, s, temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        getallpart(0, s, temp, ans);

        return ans;
    }
};