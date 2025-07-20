class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)  return {0};
        vector<int> degree(n, 0);
        unordered_map<int, vector<int>> graph;

        for(auto& edge: edges){
            degree[edge[0]] ++;
            degree[edge[1]] ++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> q;
        for(int i=0; i<n; i++){
            if(degree[i] == 1)  q.push(i);
        }

        int remain = n;
        vector<int> res;
        while(remain > 2){
            int size = q.size();
            remain -= size;
            for(int i=0; i<size; i++){
                int curr = q.front();
                q.pop();
                for(auto& nei: graph[curr]){
                    degree[nei]--;
                    if(degree[nei] == 1) q.push(nei);
                }
            }
        }
        while(!q.empty()){
            res.push_back(q.front());
            q.pop();
        }
        return res;
    }
};