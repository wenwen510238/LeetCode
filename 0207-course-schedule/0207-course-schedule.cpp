class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> visit(numCourses, 0);
        for(auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }

        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, visit))  return false;
        }
        return true;
    }  
    bool dfs(int numCourses, unordered_map<int, vector<int>>& graph, vector<int>& visit){
        if(visit[numCourses] == 1)  return false;
        if(visit[numCourses] == 2)  return true;
        
        visit[numCourses] = 1; // visiting

        for(auto& nei: graph[numCourses]){
            if(!dfs(nei, graph, visit))    return false;
        }
        visit[numCourses] = 2;// finish
        return true;
    }
};