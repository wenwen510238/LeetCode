class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string current = "";
        string res = "";
        for(int i=0; i<path.size(); i++){
            if(path[i] == '/'){
                if(current == ".." && !stk.empty()) stk.pop();
                else if(current != "" && current != "." && current != "..") stk.push(current);
                current = "";
                while(i+1<path.size() && path[i+1] == '/') i++;
            }
            else current += path[i];
        }

        if(current == ".." && !stk.empty()) stk.pop();
        else if(current != "" && current != "." && current != "..") stk.push(current);

        while(!stk.empty()){
            cout<<stk.top()<<" ";
            res = "/" + stk.top() + res;
            stk.pop();
        }
        if(res == "") return "/";
        return res;
    }
};