class Solution {
public:
    bool isPalindrome(string &str) {
        int left = 0;
        int right = str.size() - 1;

        while (left < right) {
            if (str[left] != str[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    void getallpart(string s,
                    vector<string> &temp,
                    vector<vector<string>> &ans) {

        // Base case
        if (s.empty()) {
            ans.push_back(temp);
            return;
        }

        // Try every prefix
        for (int i = 0; i < s.size(); i++) {

            string part = s.substr(0, i + 1);

            if (isPalindrome(part)) {

                // Choose
                temp.push_back(part);

                // Explore on the remaining string
                getallpart(s.substr(i + 1), temp, ans);

                // Backtrack
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> temp;

        getallpart(s, temp, ans);

        return ans;
    }
};