class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {

        int n = intervals.size();

        vector<int> start(n), end(n);

        for(int i = 0; i < n; i++) {
            start[i] = intervals[i][0];
            end[i] = intervals[i][1];
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int i = 0, j = 0;
        int curr = 0;
        int ans = 0;

        while(i < n) {

            if(start[i] <= end[j]) {
                curr++;
                i++;
                ans = max(ans, curr);
            }
            else {
                curr--;
                j++;
            }
        }

        return ans;
    }
};