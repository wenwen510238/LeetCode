class Solution {
public:
    vector<int> parent, rank;
    unordered_map<string, int> emailToId;
    unordered_map<string, string> emailToName;

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);    
        return parent[x];
    }

    void unite(int a, int b) {
        int ra = find(a), rb = find(b);
        if (ra == rb) return;
        if (rank[ra] < rank[rb]) {
            parent[ra] = rb;
        } else if (rank[ra] > rank[rb]) {
            parent[rb] = ra;
        } else {
            parent[rb] = ra;
            rank[ra]++;
        }
    }

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int id = 0;
        // Step 1：為每個 email 指派整數 id
        for (auto& acc : accounts) {
            string name = acc[0];
            for (int i = 1; i < acc.size(); ++i) {
                string& email = acc[i];
                if (!emailToId.count(email)) {
                    emailToId[email] = id++;
                    parent.push_back(parent.size());
                    rank.push_back(0);
                }
                emailToName[email] = name;
            }
        }

        // Step 2：同帳號內的 email 做 union
        for (auto& acc : accounts) {
            int first = emailToId[acc[1]];
            for (int i = 2; i < acc.size(); ++i) {
                unite(first, emailToId[acc[i]]);
            }
        }

        // Step 3：以 root 分組
        unordered_map<int, vector<string>> rootToEmails;
        for (auto& [email, idx] : emailToId) {
            int root = find(idx);
            rootToEmails[root].push_back(email);
        }

        // Step 4：組裝答案
        vector<vector<string>> res;
        res.reserve(rootToEmails.size());
        for (auto& [root, vec] : rootToEmails) {
            sort(vec.begin(), vec.end());
            vec.insert(vec.begin(), emailToName[vec[0]]);
            res.push_back(std::move(vec));
        }
        return res;
    }
};
