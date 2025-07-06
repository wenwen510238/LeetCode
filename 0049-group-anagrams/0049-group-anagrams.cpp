class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> anagramMap;
        for(string& str: strs){
            vector<int> cnt(26, 0);
            for(char c: str){
                cnt[c - 'a'] ++;
            }
            string key = "";
            for(int i=0; i<26; i++){
                key += to_string(cnt[i]) + "#";
            }

            anagramMap[key].push_back(str);
        }
        vector<vector<string>> res;
        for(auto anagram: anagramMap){
            res.push_back(move(anagram.second));
        }
        return res;
    }
};