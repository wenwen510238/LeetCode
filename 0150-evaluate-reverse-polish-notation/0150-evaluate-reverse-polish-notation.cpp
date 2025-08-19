class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> num;
        for(int i=0; i<tokens.size(); i++){
            if(tokens[i].size() > 1 || isdigit(tokens[i][0])) num.push(stoi(tokens[i]));
            else{
                int tmp1 = num.top(); num.pop();
                int tmp2 = num.top(); num.pop();
                switch(tokens[i][0]){
                    case '+':  
                        num.push(tmp2 + tmp1);
                        break;
                    case '-': 
                        num.push(tmp2 - tmp1);
                        break;
                    case '*': 
                        num.push(tmp2 * tmp1);
                        break;
                    case '/': 
                        num.push(tmp2 / tmp1);
                        break;
                }
            }
            
        }
        return num.top();
    }
};