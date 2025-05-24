class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0, startCnt = 0;
        for(int i=s.size()-1; i>=0; i--){
            if(s[i] == ' ' && startCnt == 1)   break;
            else if(s[i] != ' '){
                res++;
                startCnt = 1;
            }
        } 
        return res;
    }
};