class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> graph;
        vector<double> res;
        for(int i=0; i<equations.size(); i++){
            graph[equations[i][0]].push_back({equations[i][1], values[i]});
            graph[equations[i][1]].push_back({equations[i][0], 1.0 / values[i]});
        }

        for(auto query: queries){
            string start = query[0], end = query[1];
            
            if(graph.find(start) == graph.end() || graph.find(end) == graph.end()){
                res.push_back(-1);
                continue;
            }
            if(start == end){
                res.push_back(1.0);
                continue;
            }
        
            queue<pair<string, double>> q;
            unordered_set<string> visit;

            q.push({start, 1});
            visit.insert(start);
            int found = false;
            while(!q.empty()){
                auto [node, val] = q.front();
                q.pop();
                for(auto& [neighbor, weight]: graph[node]){
                    if(visit.count(neighbor))   continue;
                    double newVal = val * weight;
                    if(neighbor == end){
                        res.push_back(newVal);
                        found = true;
                        break;
                    }
                        
                    visit.insert(neighbor);
                    q.push({neighbor, newVal});
                }
                if(found)   break;
            }
            if(!found)  res.push_back(-1.0);
        }
        return res;
    }
};