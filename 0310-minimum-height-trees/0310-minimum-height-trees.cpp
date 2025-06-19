class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n == 1)  return {0};
        vector<vector<int>> graph(n);
        vector<int> degree(n, 0);
        for(auto& edge: edges){
            degree[edge[0]]++;
            degree[edge[1]]++;
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        queue<int> leaf;
        for(int i=0; i<n; i++){
            if(degree[i] == 1)   leaf.push(i);   
        }

        vector<int> res;
        while(!leaf.empty()){
            int size = leaf.size();
            res.clear();
            for(int i=0; i<size; i++){
                int current = leaf.front();
                leaf.pop();
                res.push_back(current);
                for(auto nei: graph[current]){
                    degree[nei]--;
                    if(degree[nei] == 1)    leaf.push(nei);
                }
            }
        }
        return res;
    }
};