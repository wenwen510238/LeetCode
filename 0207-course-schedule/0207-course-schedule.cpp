class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        queue<int> q;
        vector<int> degree(numCourses, 0);
        int finish = 0;
        for(auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            degree[pre[0]]++;
        }

        for(int i=0; i<numCourses; i++){
            if(degree[i] == 0) q.push(i);
        }
        while(!q.empty()){
            finish++;
            int num = q.front();
            q.pop();
            for(auto& nei: graph[num]){
                if(!--degree[nei])  q.push(nei);
            }
        }
        return finish == numCourses;
    }  
};