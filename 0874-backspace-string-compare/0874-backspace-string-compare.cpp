class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char> ss;
        stack<char> ts;
        for(char c: s){
            if(c != '#') ss.push(c);
            else if(!ss.empty()) ss.pop();
        }
         for(char c: t){
            if(c != '#') ts.push(c);
            else if(!ts.empty()) ts.pop();
        }
        if(ts == ss) return true;
        return false;
    }
};