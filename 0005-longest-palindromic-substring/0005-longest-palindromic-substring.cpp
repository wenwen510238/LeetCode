class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string res = "";
        for(int i=0; i<s.size(); i++){
            int l = i - 1, r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 2 + 1 > res.size())  res = s.substr(l + 1, r - l - 1);

            l = i;
            r = i + 1;
            while(l >= 0 && r < n && s[l] == s[r]){
                l--;
                r++;
            }
            if(r - l - 2 + 1 > res.size())  res = s.substr(l + 1, r - l - 1);
        }
        return res;
    }
};