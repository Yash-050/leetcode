class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        if(nums.size()==1)return 0;
        int n = nums.size();
        vector<int>mx(n ), mn(n);
        int mxi = INT_MIN;
        for(int i = 0 ;i<n;i++){
            mxi  = max(mxi , nums[i]);
            mx[i] = mxi;
        }
        mxi = INT_MAX;
        for(int i = n-1;i>=0;i--){
            mxi  =min(mxi, nums[i]);
            mn[i] = mxi;
        }
        
        for(int  i = 0;i<n;i++){
           int val  = mx[i] - mn[i];
           if(val<=k){
              return i ;  
           } 
        }
        return -1;
    }
};