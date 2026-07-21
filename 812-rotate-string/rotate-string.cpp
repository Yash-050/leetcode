class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s==goal)return true;
        if(s.size()!= goal.size())return false;
        for(int k =0 ;k<s.size();k++){//roatating k time means size time 
            char temp = s[0];//after movement select 0 th value
        for(int i =1 ;i<s.size();i++){
            
            s[i-1] = s[i];//left shift
            
        }
        s[s.size()-1] = temp;
        if(s==goal )return true;//check if equal 
        }
        return false;
    }
}; 