class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i=s.size()-1, j = t.size()-1;
        int skipS = 0, skipT = 0;
        while(i >= 0 || j >= 0){
            while(i >= 0){
                if(s[i] == '#'){
                    i--;
                    skipS++;
                }
                else if(skipS > 0){
                    i--;
                    skipS--;
                }
                else break;
            }
            while(j >= 0){
                if(t[j] == '#'){
                    j--;
                    skipT++;
                }
                else if(skipT > 0){
                    j--;
                    skipT--;
                }
                else break;
            }

            if(i >= 0 && j >= 0){
                if(s[i] != t[j]) return false;
            }
            else if(i >= 0 || j >= 0) return false;
            i--;
            j--;
        }
        return true;
    }
};