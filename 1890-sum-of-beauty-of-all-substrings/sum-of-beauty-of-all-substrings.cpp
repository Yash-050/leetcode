class Solution {
public:
    // void generater(string &s , vector<string>&t,  )
    int beautySum(string s) {
        int sum =0 ;
        for(int i =0 ;i<s.size();i++){
            unordered_map<char,int>mp;
            for(int j = i;j<s.size();j++){
                mp[s[j]]++;
                int mini = INT_MAX , maxi = INT_MIN;
                for(auto i: mp){
                    mini = min(mini,i.second);
                    maxi = max(maxi,i.second);
                }
                sum += maxi-mini;
            }
        }
        return sum;
    }
};