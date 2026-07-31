class Solution {
public:
    void help(string s, vector<string>& ans, int open, int close, int n) {

        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            help(s + "(", ans, open + 1, close, n);
        }

        if (close < open) {
            help(s + ")", ans, open, close + 1, n);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        help("", ans, 0, 0, n);
        return ans;
    }
};