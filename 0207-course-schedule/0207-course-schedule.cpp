class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0)   return true;
        unordered_map<int, vector<int>> graph;
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> visit(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, visit))   return false;
        }
        return true;
    
    }
    bool dfs(int current, unordered_map<int, vector<int>>& graph, vector<int>& visit){
        if(visit[current] == 1) return true;
        visit[current] = -1;//visiting
        for(int i=0; i<graph[current].size(); i++){
            if(visit[graph[current][i]] == -1)   return false;
            if(!dfs(graph[current][i], graph, visit))   return false;
        }
        visit[current] = 1;
        return true;
    }
};