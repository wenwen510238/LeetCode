class Solution {
public:
    bool isSubsequence(string s, string t) {
        int t_ind = 0, s_ind = 0;
        while(t_ind < t.size() && s_ind < s.size()){
            if(s[s_ind] == t[t_ind]){
                s_ind++;
                t_ind++;
            }
            else    t_ind++;
        }
        if(s_ind == s.size())   return true;
        return false;
    }
};