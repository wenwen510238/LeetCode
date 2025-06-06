class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> geneBank(bank.begin(), bank.end());
        if(!geneBank.count(endGene))    return -1;

        const char gene[4] = {'A', 'C', 'G', 'T'};
        queue<pair<string, int>> q;
        q.push({startGene, 0});

        while(!q.empty()){
            auto [curr, step] = q.front();
            q.pop();
            if(curr == endGene) return step;
            for(int i=0; i<curr.size(); i++){
                char c = curr[i];
                for(char g: gene){
                    if(g == c)    continue;
                    curr[i] = g;
                    if(geneBank.count(curr)){
                        q.push({curr, step+1});
                        geneBank.erase(curr);
                    }
                }
                curr[i] = c;
            }
        }
        return -1;
    }
};