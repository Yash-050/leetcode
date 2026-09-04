class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> st;
        vector<int>ans(nums.size());
        for(int i = 2*nums.size()-1;i>=0;i--){
            while(!st.empty()&&st.top()<= nums[i%nums.size()])st.pop();//maintaining decreasing montonic stack 
            if(i<nums.size()){//putting value only when i is orignal 
                ans[i] = st.empty()?-1:st.top();
            }
            st.push(nums[i%nums.size()]);
        }
        return ans;
    }
};