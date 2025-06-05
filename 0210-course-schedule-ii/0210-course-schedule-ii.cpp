class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int, vector<int>> graph;
        vector<int> inDegree(numCourses, 0);
        vector<int> res;
        for(auto& pre: prerequisites){
            graph[pre[1]].push_back(pre[0]);
            inDegree[pre[0]]++;
        }
        
        queue<int> canHave;
        for(int i=0; i<numCourses; i++){
            if(inDegree[i] == 0)    canHave.push(i);
        }

        while(!canHave.empty()){
            int current = canHave.front();
            canHave.pop();
            res.push_back(current);
            for(int c: graph[current]){
                inDegree[c]--;
                if(inDegree[c] == 0)    canHave.push(c);
            }
        }
        if(res.size() == numCourses)    return res;
        return {};
    }
};