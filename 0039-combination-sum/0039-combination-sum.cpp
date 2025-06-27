class Solution {
    vector<vector<int>> res;
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> path;
        dfs(candidates, target, path, 0);
        return res;
    }

    void dfs(vector<int>& candidates, int target, vector<int>& path, int idx){
        if(target == 0){
            res.push_back(path);
            return;
        }
        if(target < 0 || idx >= candidates.size()) return;

        // for(int i=idx; i<candidates.size(); i++){
        path.push_back(candidates[idx]);
        dfs(candidates, target-candidates[idx], path , idx);
        path.pop_back();
        dfs(candidates, target, path , idx+1);
        // }
    }
};