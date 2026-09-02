class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;int n = nums1.size(), n2 = nums2.size();
        unordered_map<int,int>mp;//for storing mp and nge as key value 
        for(int i = n2-1;i>=0;i--){
            while(!st.empty()&&nums2[i]>=st.top())st.pop();
            if(st.empty())mp[nums2[i]] = -1;
            else mp[nums2[i]] = st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i :nums1){
            ans.push_back(mp[i]);
        }
        return ans;

    }
};