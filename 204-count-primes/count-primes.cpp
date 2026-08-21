class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, 1);
        int cnt = 0;

        //for making all the even numbers 0 because 2 is the only even prime
        for(int i = 4; i < n; i += 2){
            prime[i] = 0;
        }

        //for making the next condition and decreasing comparison
        for(int i = 3; i * i < n; i += 2){
            if(prime[i] == 1){

                //for making all the multiple of prime 0
                //we use 2*i because all the even multiples are already 0
                for(int j = i * i; j < n; j += 2 * i){
                    prime[j] = 0;
                }
            }
        }

        //2 is also a prime
        cnt = 1;

        for(int i = 3; i < n; i += 2){
            if(prime[i] == 1)
                cnt++;
        }

        return cnt;
    }
};