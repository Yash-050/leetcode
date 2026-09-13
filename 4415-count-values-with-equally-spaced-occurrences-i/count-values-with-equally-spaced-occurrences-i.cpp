class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n =  nums.size();int cnt = 0 ;
        unordered_map<int,int>mp;
        for(int i :nums)mp[i]++;
        for(int i =0 ;i<n;i++){
            for(int j = i+1;j<n;j++){
                for(int k = j+1;k<n;k++){
                    if(nums[i]==nums[j]&&nums[j]==nums[k]&&mp[nums[i]]==3){
                       if(j-i == k-j)cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};