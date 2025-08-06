class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for(auto& token: tokens){
            if(token !=  "+" && token !=  "-" && token !=  "*" && token !=  "/" )    stk.push(stoi(token));
            else{
                int num1 = stk.top();
                stk.pop();
                int num2 = stk.top();
                stk.pop();
                if(token == "+") stk.push(num2 + num1);
                else if(token == "-") stk.push(num2 - num1);
                else if(token == "*") stk.push(num2 * num1);
                else if(token == "/") stk.push(num2 / num1);
            }
        }
        return stk.top();
    }
};