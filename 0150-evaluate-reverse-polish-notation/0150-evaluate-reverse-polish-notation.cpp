class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto& token: tokens){
            if(token.size() > 1 || isdigit(token[0]))    stk.push(stoi(token));
            else{
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                switch(token[0]){
                    case '+':  
                        stk.push(num2 + num1);
                        break;
                    case '-': 
                        stk.push(num2 - num1);
                        break;
                    case '*': 
                        stk.push(num2 * num1);
                        break;
                    case '/': 
                        stk.push(num2 / num1);
                        break;
                }
            }
        }
        return stk.top();
    }
};