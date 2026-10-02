class Solution {
public:
    bool valid(string s) {
        int balance = 0;

        for (char c : s) {
            if (c == '(') {
                balance++;
            } 
            else {
                balance--;

                if (balance < 0)
                    return false;
            }
        }

        return balance == 0;
    }

    void help(string &s, vector<string>& ans, int idx, int n) {
        if (idx == 2 * n) {
            ans.push_back(s);
            return;
        }

        s.push_back('(');
        help(s, ans, idx + 1, n);
        s.pop_back();

        s.push_back(')');
        help(s, ans, idx + 1, n);
        s.pop_back(); // good practice
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string s = "";

        help(s, ans, 0, n);

        vector<string> a;

        for (string i : ans) {
            if (valid(i)) {
                a.push_back(i);
            }
        }

        return a;
    }
};