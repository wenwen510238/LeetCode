class Solution {
public:
    struct cmp{
        bool operator()(const pair<int, string>& a, const pair<int, string>& b){
            if(a.first == b.first) return a.second < b.second;
            return a.first > b.first;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> mp;
        vector<string> res(k, "");
        for(string& s: words){
            mp[s]++;
        }
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;

        for(auto& p: mp){
            pq.push({p.second, p.first});
            if(pq.size() > k) pq.pop();
        }

        for(int i=k-1; i>=0; i--){
            res[i] = (pq.top().second);
            pq.pop();
        }
        return res;
    }
};