class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, vector<string>> emailGraph;
        unordered_map<string, string> emailToName;
        for(auto& acc: accounts){
            for(int i=1; i<acc.size(); i++){
                emailToName[acc[i]] = acc[0];
                emailGraph[acc[i]];
                if(i != 1){
                    emailGraph[acc[1]].push_back(acc[i]);
                    emailGraph[acc[i]].push_back(acc[1]);
                }
            }
        }

        unordered_set<string> visit;
        vector<vector<string>> res;
        for(auto& [email, _]: emailGraph){
            if(visit.count(email))  continue;

            vector<string> comp;
            queue<string> q;
            q.push(email);
            visit.insert(email);

            while(!q.empty()){
                string node = q.front();
                q.pop();
                comp.push_back(node);
                for(auto& nei: emailGraph[node]){
                    if(!visit.count(nei)){
                        visit.insert(nei);
                        q.push(nei);
                    }
                }
            }
            sort(comp.begin(), comp.end());
            comp.insert(comp.begin(), emailToName[email]);
            res.push_back(comp);
        }
        return res;
    }
};