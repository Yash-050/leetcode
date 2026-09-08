class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int>nse(n) , pse(n);
        stack<int>st;
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]>= nums[i])st.pop();
            if(st.empty())nse[i] = n;
            else nse[i] = st.top(); 

            st.push(i);
        }
        while(!st.empty())st.pop();
        for(int i = 0 ;i<n;i++){
            while(!st.empty()&&nums[st.top()]>nums[i])st.pop();
            if(st.empty())pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        long long ans1 = 0 ,ans2 = 0 ; 
        for(int i = 0 ;i<n;i++){
            long long left = i-pse[i];
            long long  right = nse[i] - i;
            ans1 += 1LL*(left *right*nums[i]);
        }
        // nse.clear();pse.clear();
        while(!st.empty())st.pop();
        for(int i = n-1;i>=0;i--){
            while(!st.empty()&&nums[st.top()]<= nums[i])st.pop();
            if(st.empty())nse[i] = n;
            else nse[i] = st.top();
            st.push(i); 
        }
        while(!st.empty())st.pop();
        for(int i = 0 ;i<n;i++){
            while(!st.empty()&&nums[st.top()]<nums[i])st.pop();
            if(st.empty())pse[i] = -1;
            else pse[i] = st.top();
            st.push(i);
        }
        for(int i = 0 ;i<n;i++){
            long long left = i-pse[i];
            long long right = nse[i] - i;
            ans2 += 1LL*(left *right*nums[i]);
        }
        return ans2-ans1;
    }
};