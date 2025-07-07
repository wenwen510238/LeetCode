class Solution {
public:
    int longestPalindrome(string s) {
        unordered_set<char> letter;
        int res = 0;
        for(auto& c: s){
            if(!letter.count(c)) letter.insert(c);
            else{
                res+=2;
                letter.erase(c);
            }
        } 
        if(letter.size() > 0)   return res+1;
        return res;
    }
};