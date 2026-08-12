class Solution {
public:
    int hammingWeight(int n) {//by finding the binary string
        string s  = "";
        while(n!=0){
           if(n%2 == 0)s.push_back('0');
           else s.push_back('1');
           n = n/2;
        }
        reverse(s.begin(),s.end());
        int cnt = 0 ;
        for(char c:s){
            if(c=='1')cnt++;
        }
        return cnt;
    }
};