class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(auto c: s){
            if(c == '{' || c == '(' || c == '[') stk.push(c);
            else{
                switch(c){
                    case '}':
                        if(!stk.empty() && stk.top() == '{') stk.pop();
                        else return false;
                        break;
                    case ')':
                        if(!stk.empty() && stk.top() == '(') stk.pop();
                        else return false;
                        break;
                    case ']':
                        if(!stk.empty() && stk.top() == '[') stk.pop();
                        else return false;
                        break;
                }
            }
        }
        if(!stk.empty()) return false;
        return true;
    }
};