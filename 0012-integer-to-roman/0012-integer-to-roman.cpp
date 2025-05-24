class Solution {
public:
    string intToRoman(int num) {
        string s = "";
        vector<int> integer = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
        vector<string> sym = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
        int idx = integer.size() - 1;
        while(idx >= 0){
            while(num >= integer[idx]){
                s += sym[idx];
                num -= integer[idx];
            }
            idx--;
        }
        return s;
    }
};