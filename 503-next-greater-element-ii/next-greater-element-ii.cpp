class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int i = 0;
        vector<int> ans;

        while (i < nums.size()) {
            int val = -1;
            bool found = false;

            // Search to the right
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] > nums[i]) {
                    val = nums[j];
                    found = true;
                    break;
                }
            }

            // Search from beginning only if not found
            if (!found) {
                for (int j = 0; j < i; j++) {
                    if (nums[j] > nums[i]) {
                        val = nums[j];
                        found = true;
                        break;
                    }
                }
            }

            ans.push_back(val);
            i++;
        }

        return ans;
    }
};