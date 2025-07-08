class Solution {
public:
    int myAtoi(string s) {
        int res = 0;
        int sign = 1, n = s.size(), i = 0;
        
        // step 1: skip whitespace
        while(i < n && s[i] == ' ' ) i++;

        // step 2: check sign
        if(i < n && (s[i] == '-' || s[i] == '+')){
            if(s[i] == '-') sign = -1;
            i++;
        }

        //step 3: read digit
        while(i<n && isdigit(s[i])){
            int digit = s[i] - '0';
            if(res > (INT_MAX - digit) / 10)    return sign == 1 ? INT_MAX : INT_MIN;
            
            res = res * 10 + digit;
            i++;
        }
        return sign * res;

    }
};