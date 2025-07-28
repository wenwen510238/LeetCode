class Solution {
public:
    vector<string> digitToLetter = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0)  return {};
        string combined = "";
        vector<string> res;
        backtracking(digits, combined, res, 0);
        return res;
    }

    void backtracking(string digits, string& combined, vector<string>& res, int idx){
        if(idx == digits.size()){
            res.push_back(combined);
            return;
        }
        int digit = digits[idx] - '2';
        for(char ch : digitToLetter[digit]){
            combined += ch;
            backtracking(digits, combined, res, idx+1);
            combined.pop_back();
        }
    }
};