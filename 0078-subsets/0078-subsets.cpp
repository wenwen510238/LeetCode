class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool> used(nums.size(), false);
        vector<int> path;
        backtracking(nums, res, path, used, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, vector<bool>& used, int idx){
        res.push_back(path);
        for(int i=idx; i<nums.size(); i++){
            if(used[i]) continue;

            used[i] = true;
            path.push_back(nums[i]);

            backtracking(nums, res, path, used, i+1);
            path.pop_back();
            used[i] = false;
        }
    }
};