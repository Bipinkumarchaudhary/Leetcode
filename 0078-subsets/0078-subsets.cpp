class Solution {
public:    
    void subsetHelper(int idx, vector<int>& nums, int n, vector<int> &temp, vector<vector<int>>& ans) {
        if (idx == n) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[idx]);
        subsetHelper(idx+1, nums, n, temp, ans);
        temp.pop_back();
        subsetHelper(idx+1, nums, n, temp, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> temp;
        subsetHelper(0, nums, n, temp, ans);
        return ans;
    }
};