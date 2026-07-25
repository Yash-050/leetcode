class Solution {
public:
    int start = 0, maxi = 1;
    // writting the check function is a bit tricky
    void check(string& s, int i, int j) {
        while (i >= 0 && j < s.size() &&
               s[i] == s[j]) {   // it simply means checking from the left and
                                 // right part palindrome part
            int len = j - i + 1; // it is mean to see for the greater size part
            if (len > maxi) {
                maxi = len;
                start = i;
            }
            // an important part i say since we are checking for the palindrome
            // int it

            i--, j++;
        }
    }
    string longestPalindrome(string s) {
        for (int i = 0; i < s.size(); i++) {
            check(s, i, i);     // for checking when palindrome start from the
                                // single element
            check(s, i, i + 1); // it's when there are two same value from where
                                // palindrome starts i.e case 2
        }
        return s.substr(start, maxi);
    }
};