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
        if(target < 0) return;

        for(int i=idx; i<candidates.size(); i++){
            path.push_back(candidates[i]);
            dfs(candidates, target-candidates[i], path , i);
            path.pop_back();
        }
    }
};