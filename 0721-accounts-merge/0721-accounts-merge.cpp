class Solution {
public:
    unordered_map<string, string> emailToName;
    unordered_map<string, string> parent;

    string find(string s){
        if(parent[s] != s) parent[s] = find(parent[s]);  
        return parent[s];
    }

    void unite(string a, string b){
        parent[find(a)] = find(b);
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto& acc: accounts){
            for(int i=1; i<acc.size(); i++){
                emailToName[acc[i]] = acc[0];
                parent[acc[i]] = acc[i];
            }
        }

        for(auto& acc: accounts){
            for (int i = 2; i < acc.size(); ++i) {
                unite(acc[i - 1], acc[i]);
            }
        }

        unordered_map<string, vector<string>> rootToEmails;
        for(auto& [email, _]: emailToName){
            string root = find(email);
            rootToEmails[root].push_back(email);
        }

        vector<vector<string>> res;
        for(auto& [root, emails]: rootToEmails){
            sort(emails.begin(), emails.end());
            emails.insert(emails.begin(), emailToName[root]);
            res.push_back(emails);
        }
        return res;
    }
};