class Solution {
public:
    void help(int idx, string &s, vector<string>&ans, string digits ,unordered_map<char,string>mp){
        if(idx>=digits.size()){ans.push_back(s);return ;}
        
         char c = digits[idx];string val  = mp[c];
         for(int i =0 ;i<val.size();i++){
            s.push_back(val[i]);
            help(idx+1, s,ans,digits,mp);
            s.pop_back();
         }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string> ans;
        string s;
        help(0, s, ans, digits, mp);
        return ans;
    }
};