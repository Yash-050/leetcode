class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mp1;for(char i :s)mp1[i]++;
        unordered_map<char,int>mp2;for(char i:t)mp2[i]++;
        if(mp1==mp2)return true;
        return  false;
    }
};