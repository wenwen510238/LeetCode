class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMapping;
        bracketMapping['{'] = '}';
        bracketMapping['['] = ']';
        bracketMapping['('] = ')';
        for(auto& c: s){
            if(c == '(' || c == '{' || c == '[') stk.push(c);
            else{
                if(stk.empty()) return false;
                char top = stk.top();
                if(c != bracketMapping[top]) return false;
                else stk.pop();
            }
        }
        if(stk.empty()) return true;
        return false;
    }
};