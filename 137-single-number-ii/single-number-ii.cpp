class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int bitidx =0 ;bitidx<32;bitidx++){//for counting of  count in each bit line 
            int cnt =0 ;
            for(int i =0 ;i<nums.size();i++ ){ // for comapring it to the last bit of the given number 
                if(nums[i]&(1<<bitidx))cnt++;
            }
            if(cnt%3==1){//if not multiple of 3 
                ans = ans | (1<<bitidx);
            }
        }
        return ans;
    }
};