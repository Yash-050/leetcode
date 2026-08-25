class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0; vector<int>ans;
        int i =0 ;int j = nums.size()-1;
        while(i<j){
            sum = nums[i]+ nums[j];
            if(sum ==target){
                ans.push_back(i+1);
                ans.push_back(j+1);
                break;
            }
            if(sum<target){i++;}
            if(sum>target){j--;}
        }
        return ans;
    }
};