class Solution {
public:
    string convertbinary(int n ){
        string a = "";
        for(int i  = 7;i>=0;i--){
           a += ((n >> i) & 1) + '0';
        }
        return a ;
    }
    bool ispalindrome(string s){
        int i =0 ,j = s.size()-1;
        while(i<j){
            if(s[i]== s[j])i++,j--;
            else if(s[i]!= s[j])return false;
        
        }
        return true ;
    }
    bool isPalindromic(string s) {
        string t = "";
        for(char c:s){
            int val = c;
            t += convertbinary(val);
        }
        if(ispalindrome(t))return true ;
        return false ;
    }
};