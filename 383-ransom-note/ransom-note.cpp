class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mp1, mp2;

        for(char c : ransomNote)
            mp1[c]++;

        for(char c : magazine)
            mp2[c]++;

        for(int i = 0; i < ransomNote.size(); i++) {
            if(mp1[ransomNote[i]] > mp2[ransomNote[i]])
                return false;
        }

        return true;
    }
};