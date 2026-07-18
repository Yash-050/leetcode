class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;//creating stack
        string ans;

        for (char c : s) {
            if (c == '(') {//only choosing condn
                if (!st.empty())//when not empty 
                    ans += c;
                st.push(c);
            } else {
                st.pop();
                if (!st.empty())//for ')'this 
                    ans += c;
            }
        }

        return ans;
    }
};