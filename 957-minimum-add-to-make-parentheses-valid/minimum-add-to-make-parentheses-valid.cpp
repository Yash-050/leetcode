class Solution {
public:
    int minAddToMakeValid(string s) {
        if(s.empty())return 0;
        stack<char>st;int cnt = 0 ;
        for(char c: s){
            if(c=='(')st.push(c);
            else if(c==')'){
                if(st.empty())cnt++;
                else st.pop();
            }
        }
        cnt += st.size();
        return cnt;
    }
};