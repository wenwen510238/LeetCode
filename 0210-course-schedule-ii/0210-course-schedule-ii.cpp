class Solution {
public:
    unordered_map<int, vector<int>> graph;
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        for(auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> visit(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, visit, res))  return {};
        }
        reverse(res.begin(), res.end());
        return res;
    }

    bool dfs(int current, vector<int>& visit, vector<int>& res){
        if(visit[current] == -1)    return false;
        else if(visit[current] == 1)    return true;
        visit[current] = -1;
        for(auto& nei: graph[current]){
            if(!dfs(nei, visit, res))   return false;
        }

        res.push_back(current);
        visit[current] = 1;
        return true;
    }
};