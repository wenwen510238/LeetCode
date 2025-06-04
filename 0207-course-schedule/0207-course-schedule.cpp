class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size() == 0)   return true;
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses, 0);
        for(auto pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        queue<int> q;
        int complete = 0;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0)   q.push(i);
        }
        while(!q.empty()){
            int current = q.front();
            q.pop();
            complete++;
            for(auto& neighbor: graph[current]){
                inDegree[neighbor]--;
                if(!inDegree[neighbor]) q.push(neighbor);
            }
        }
        return complete == numCourses;
    
    }
};