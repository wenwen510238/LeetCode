class Solution {
public:
    string simplifyPath(string path) {
        vector<string> parts;
        string current = "";
        string res = "/";
        for(int i=0; i<=path.size(); i++){
            if(i == path.size() || path[i] == '/'){
                if(current == ".." && !parts.empty()) parts.pop_back();
                else if(current != "" && current != "." && current != "..") parts.push_back(current);
                current = "";
                while(i+1<path.size() && path[i+1] == '/') i++;
            }
            else current += path[i];
        }

        if(parts.empty()) return "/";
        for(int i=0; i<parts.size(); i++){
            res += parts[i] + '/' ;
        }
        return res.substr(0, res.size()-1);
    }
};