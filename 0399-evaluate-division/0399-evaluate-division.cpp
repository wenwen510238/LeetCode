class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> graph;
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> res;
        // build directed tree
        for(int i=0; i<equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        for(auto& query: queries){
            string start = query[0], end = query[1];
            if(!graph.count(start) || !graph.count(end))    res.push_back(-1.0);
            else if(start == end)   res.push_back(1.0);
            else{
                unordered_set<string> visit;
                double result = dfs(start, end, visit, 1.0);
                res.push_back(result);
            }
        }
        return res;
    }
    double dfs(string start, string end, unordered_set<string>& visit, double product){
        if(start == end)    return product;
        visit.insert(start);

        for(auto& [neighbor, weight]: graph[start]){
            if(visit.count(neighbor))   continue;
            double result = dfs(neighbor, end, visit, product * weight);
            if(result != -1)   return result;      
        }
        return -1;
    }
};