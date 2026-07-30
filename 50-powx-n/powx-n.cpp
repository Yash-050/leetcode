class Solution {
public:
    double myPow(double x, int n) {
        long long N = n ;
        if(N==0)return 1.0000;
        if(N<0){
            x = 1/x;
            N = -1*N;
        }
        if(n == 1)return x;
        long long half = N/2;
        double val =myPow(x,half);
        if(N%2==0){
            return (val*val);
        }
        return (val*val*x);
    }
};