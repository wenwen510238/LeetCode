class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, int> anagramMap;
        for(auto& str: strs){
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            if(!anagramMap.count(tmp)){
                anagramMap[tmp] = res.size();
                res.push_back({str});
            }
            else{
                int idx = anagramMap[tmp];
                res[idx].push_back(str);
            }
        }
        return res;
    }
};