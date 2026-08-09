class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;         // handle negatives & zero
        if (n == 1) return true;          // base case
        if (n % 2 != 0) return false;     // odd → not power of 2
        return isPowerOfTwo(n / 2);
    }
};