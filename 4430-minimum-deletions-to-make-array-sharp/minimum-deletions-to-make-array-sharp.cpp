class Solution {
public:
    int minDeletions(vector<int>& nums) {
        int cnt = 0 ;
        for(int i =0 ;i<nums.size();i++){
            if(i+1<nums.size()&&nums[i] == nums[i+1])cnt++;
        }        
        return cnt;
    }
};