class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mp;   
        stack<int> st;

 
        for(int i = nums2.size()-1; i >= 0; i--) {

            int ele = nums2[i];

 
            while(!st.empty() && st.top() <= ele) {
                st.pop();
            }

 
            if(st.empty()) mp[ele] = -1;
            else mp[ele] = st.top();


            st.push(ele);
        }


        vector<int> ans;
        for(int x : nums1) {
            ans.push_back(mp[x]);
        }

        return ans;
    }
};