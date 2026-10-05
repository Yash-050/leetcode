class Solution {
public:
    int reverse(int x) {
        string s = to_string(x);

        std::reverse(s.begin(), s.end());

        bool negative = false;

        if (s.back() == '-') {
            negative = true;
            s.pop_back();
        }

        long long num = stoll(s);

        if (negative)
            num = -num;

        if (num > INT_MAX || num < INT_MIN)
            return 0;

        return (int)num;
    }
};