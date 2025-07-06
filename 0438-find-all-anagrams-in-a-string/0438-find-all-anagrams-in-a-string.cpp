class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector< int> pCnt(26, 0), sCnt(26, 0);
        vector<int> res;
        for(char c: p){
            pCnt[c-'a'] ++;
        }
        
        for(int i=0; i<s.size(); i++){
            sCnt[s[i] - 'a'] ++;
            if(i >= p.size())   sCnt[s[i-p.size()] - 'a']--;
            if(pCnt == sCnt)    res.push_back(i - p.size() + 1);
        }
        return res;
    }
};