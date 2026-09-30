class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()<=1)return 0;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        int i = 0, j = 1;int cnt  = 0 ;
        while(j<intervals.size()){
            if(intervals[i][1]>intervals[j][0]){j++; cnt++;}
            else if (intervals[i][1]<=intervals[j][0]){
                i= j;
                j++;
            }
        }
        return cnt;
    }
};