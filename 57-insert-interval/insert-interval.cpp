class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        intervals.push_back(newInterval);
        if (intervals.size() <= 1)
            return intervals;

        sort(intervals.begin(), intervals.end());

        vector<vector<int>> ans;
        vector<int> prev = intervals[0];

        for (int i = 1; i < intervals.size(); i++) {
            int curr = intervals[i][0];

            if (prev[1] >= curr) {
                prev[1] = max(prev[1], intervals[i][1]);
            } else {
                ans.push_back(prev);
                prev = intervals[i];
            }
        }

        ans.push_back(prev);

        return ans;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {}
// };
