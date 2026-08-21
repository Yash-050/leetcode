class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xr = 0 ;
        for(int i =0 ;i<nums.size();i++){
            xr = xr ^nums[i];//for finding the shifted bit value 
        }
        int rightmost = xr & (-xr);//for the rightmost set bit 
        int b1 =0 , b2 = 0 ;
        for(int i =0 ;i<nums.size();i++){
            if(nums[i]&rightmost)//when the the rightmost is 1
             b1 = b1^nums[i];
            else 
              b2 = b2^nums[i];
        }
        return {b1 , b2};
    }
};