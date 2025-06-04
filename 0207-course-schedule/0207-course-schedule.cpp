class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0)   return true;
        vector<vector<int>> graph(numCourses);
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
        }
        vector<int> visit(numCourses, 0);
        for(int i=0; i<numCourses; i++){
            if(!dfs(i, graph, visit))   return false;
        }
        return true;
    
    }
    bool dfs(int current, vector<vector<int>>& graph, vector<int>& visit){
        if(visit[current] == 1) return true;
        else if(visit[current] == -1)   return false;
        
        visit[current] = -1;//visiting
        for(int neighbor: graph[current]){
            if(!dfs(neighbor, graph, visit))   return false;
        }
        visit[current] = 1;//done
        return true;
    }
};