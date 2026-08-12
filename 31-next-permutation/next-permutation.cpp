class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int pivot = -1;
        int n = nums.size();
        //finding pivot (only value from which is smaller then right one)
        for (int i = n - 1; i >= 0; i--) {
            if (i >= 1 && nums[i - 1] < nums[i]) {
                pivot = i - 1;
                break;
            }
        }
        //acc to condition
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        //for making just greater value in the permutation 
        for (int i = n - 1; i > pivot;i--){
            if(nums[i]>nums[pivot]){
                swap(nums[i], nums[pivot]);
                break;
            }
        }
        //reversing for getting the max value 
        
        int i = pivot+1 , j = n-1;
        while(i<=j){
            swap(nums[i] , nums[j]);
            i++, j--;
        }
    }
};