class Solution {
public:
    string decodeString(string s) {
        stack<int> countStk;
        stack<string> strStack;
        int num = 0;
        string curr = "";

        for(auto& c: s){
            if(isdigit(c)){
                num = num * 10 + c - '0';
            }
            else if(c == '['){
                countStk.push(num);
                strStack.push(curr);
                num = 0;
                curr = "";
            }
            else if(c == ']'){
                string repeat = "";
                int k = countStk.top();
                countStk.pop();
                string prev = strStack.top();
                strStack.pop();

                for(int i=0; i<k; i++) repeat += curr;
                curr = prev + repeat;
            }
            else{ //char
                curr += c;
            }
        }
        return curr;
    }
};