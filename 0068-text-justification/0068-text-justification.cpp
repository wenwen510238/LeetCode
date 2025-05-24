class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> curLines;
        int curLen = 0;
        vector<string> res;

        for(int i=0; i<words.size(); i++){
            if(curLen + words[i].size() + curLines.size() > maxWidth){
                res.push_back(justifyLine(curLines, curLen, maxWidth, false));
                curLines.clear();
                curLen = 0;
            }
            curLen += words[i].size();
            curLines.push_back(words[i]);
        }
        
        res.push_back(justifyLine(curLines, curLen, maxWidth, true));
        return res;

    }
private:
    string justifyLine(vector<string> lines, int curLen, int maxWidth, bool isLast){
        int space = maxWidth - curLen;
        string res;

        if(lines.size() == 1){
            res += lines[0] + string(space, ' ');
        }
        else if(isLast){
            for(int i=0; i<lines.size(); i++){
                res += lines[i];
                if(i!=lines.size()-1)   res += " ";
            }
            res += string(maxWidth - curLen - (lines.size()-1), ' ');
        }
        else{
            int even = space / (lines.size() - 1);
            int remain = space % (lines.size() - 1);
            for(int i=0; i<lines.size(); i++){
                res += lines[i];
                if(i != lines.size()-1 && i < remain) res += string(even+1, ' ');
                else if(i != lines.size()-1 && i >= remain) res += string(even, ' ');
            }
        }
        return res;
    }
};