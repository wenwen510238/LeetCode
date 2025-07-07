class Solution {
public:
    int longestPalindrome(string s) {
        int letter[128] = {0};
        int res = 0;

        for(auto& c: s) letter[c]++;
        
        for(int i=0; i<128; i++){
            res += (letter[i] / 2) * 2;
        }
        if(s.size() > res)   return res + 1;
        return res;
    }
};