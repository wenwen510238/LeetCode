class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string cur = "";
        int firstSpace = 0;
        for(int i=0; i<s.size(); i++){
            if(s[i] == ' ')    firstSpace = i;
            else    break;
        }
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] != ' ')    cur = s[i] + cur;
            else if(s[i] == ' ' && cur != ""){
                res += cur;
                cur  = "";
                if(i != firstSpace)  res += " ";
            }
        }
        if(cur != "")  res += cur;
        return res;
    }
};