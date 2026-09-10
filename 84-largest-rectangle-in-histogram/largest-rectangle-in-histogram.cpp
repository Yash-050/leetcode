class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int>st ;int n = h.size();
        vector<int>right(n);vector<int>left(n);
        //right smaller nearest 
        for(int i =n-1;i>=0;i-- ){
            while(st.size()>0 && h[i]<=h[st.top()]  ){
                st.pop();
            }
            right[i] = st.empty()?n:st.top();
            st.push(i);
        }
                while(!st.empty()) st.pop();
        //left smallest 
        for(int i = 0;i<n;i++){
            while(st.size()>0 && h[i]<=h[st.top()]  ){
                st.pop();
            }
            left[i] = st.empty()?-1:st.top();
            st.push(i);
        }
        int maxi = 0;
        for(int i = 0;i<n;i++){
            int width = right[i] - left[i] - 1;
            int area = h[i]*width;
            maxi = max(maxi , area);
        }
        return maxi;
    }
};