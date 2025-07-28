class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        backtracking(nums, res, path, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int idx){
        res.push_back(path);
        for(int i=idx; i<nums.size(); i++){
            path.push_back(nums[i]);

            backtracking(nums, res, path, i+1);
            path.pop_back();
        }
    }
};