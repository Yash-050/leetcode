class Solution {
public:
    void helper(int idx, string &s,vector<string>&ans,string digit,unordered_map<char,string>mp) {
        //base case
        if(idx>=digit.size()){
            ans.push_back(s);
            return ;
        }
        char n = digit[idx];//for integer value
        string val = mp[n];//for string value
        for(int i =0 ;i<val.size();i++){
            s.push_back(val[i]);
            helper(idx+1, s,ans,digit,mp);
            s.pop_back();
        }

    }
    vector<string> letterCombinations(string digit) {
        unordered_map<char,string>mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        vector<string>ans;
        string s;
        helper(0 , s,ans,digit,mp);
        return ans;
    }
};