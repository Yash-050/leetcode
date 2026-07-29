class Solution {
public:
    int myAtoi(string s) {

        int i = 0;
        int n = s.size();
        long long nums = 0;      // Use long long for overflow checking
        int sign = 1;

        // Step 1: Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Step 2: Check for optional sign
        if (i < n && s[i] == '+') {
            i++;
        }
        else if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }

        // Step 3: Read consecutive digits
        while (i < n && isdigit(s[i])) {

            nums = nums * 10 + (s[i] - '0');

            // Step 4: Handle overflow
            if (sign == 1 && nums > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -nums < INT_MIN)
                return INT_MIN;

            i++;
        }

        return nums * sign;
    }
};