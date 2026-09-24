class Solution {
public:
    int check(int n ){
        int sum =0 ;
        while(n!=0){
            int d  = n%10;
            sum += d;
            n = n/10; 
        }
        return sum ;
    }
    int smallestIndex(vector<int>& nums) {
        for(int  i =0 ;i<nums.size();i++){
            int  sum = check(nums[i]);
            if(sum == i)return sum;
        }
        return -1;
    }
};