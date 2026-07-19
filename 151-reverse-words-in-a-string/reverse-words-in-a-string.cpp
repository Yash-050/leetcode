class Solution {
public:
    string reverseWords(string s) {
        vector<string> wvec;
        int i = 0;
        int n = s.size();

        while (i < n) {

            // Skip spaces
            while (i < n && s[i] == ' ')
                i++;

            string word = "";

            // Read one word and store in it 
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }

            // Store the word
            if (!word.empty())
                wvec.push_back(word);
        }

        // Reverse the wvec
        reverse(wvec.begin(), wvec.end());

        // then the stored with space 
        string ans = "";

        for (int i = 0; i < wvec.size(); i++) {
            ans += wvec[i];

            if (i != wvec.size() - 1)
                ans += " ";
        }

        return ans;
    }
};