class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i :asteroids){
            //for the condition where the deletion happen but with control 
            while(!st.empty()&&i<0&&st.top()>0){
                if(abs(i)>abs(st.top())){//for negative greater
                   st.pop();
                }
                else if(abs(i)==abs(st.top())){i = 0 , st.pop();break;}
                else{ i = 0  ; break;}  
            }
            if(i!=0 )st.push(i);


        }
        vector<int>ans(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            ans[i] = st.top();
            st.pop();
        }

        return ans;
    }
};