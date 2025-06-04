class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        for(auto& pre: prerequisites){
            graph[pre[0]].push_back(pre[1]);
        }
        vector<int> state(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, state))   return false;
        }
        return true;
    }
    bool dfs(int course, vector<vector<int>>& graph, vector<int>& state){
        if(state[course] == 1)  return false;
        else if(state[course] == 2) return true;
        state[course] = 1;//visiting
        for(auto neighbor: graph[course]){
            if(!dfs(neighbor, graph, state))  return false;
        }
        state[course] = 2;//done
        return true;
    }
};