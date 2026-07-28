class Solution {
public:
    int myAtoi(string s) {

        int n = s.size();
        int i = 0;

        // We use long long because the number may become larger
        // than INT_MAX while we are constructing it.
        long long ans = 0;

        // Assume the number is positive unless we see '-'
        int sign = 1;

        // ----------------------------------------------------
        // STEP 1 : Skip all leading spaces
        // Example:
        // "    -42"
        //      ^
        // We keep moving until we reach a non-space character.
        // ----------------------------------------------------
        while (i < n && s[i] == ' ')
            i++;

        // ----------------------------------------------------
        // STEP 2 : Check if there is a sign
        // If '-' then remember it.
        // If '+' just skip it.
        // ----------------------------------------------------
        if (i < n && s[i] == '-') {
            sign = -1;
            i++;
        }
        else if (i < n && s[i] == '+') {
            i++;
        }

        // ----------------------------------------------------
        // STEP 3 : Read digits one by one.
        // Stop automatically when we see a non-digit.
        // Example:
        // "123abc"
        //
        // ans = 1
        // ans = 12
        // ans = 123
        // stop at 'a'
        // ----------------------------------------------------
        while (i < n && isdigit(s[i])) {

            // Convert character into actual digit
            int digit = s[i] - '0';

            // Build the number
            ans = ans * 10 + digit;

            // ------------------------------------------------
            // STEP 4 : Overflow handling
            // If answer exceeds INT_MAX or INT_MIN,
            // return immediately.
            // ------------------------------------------------
            if (sign == 1 && ans > INT_MAX)
                return INT_MAX;

            if (sign == -1 && -ans < INT_MIN)
                return INT_MIN;

            i++;
        }

        // ----------------------------------------------------
        // STEP 5 : Apply the sign
        // ----------------------------------------------------
        return sign * ans;
    }
};