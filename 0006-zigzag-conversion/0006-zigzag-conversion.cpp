class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1)    return s;
        string res = "";
        int round  = 2 * (numRows - 1);
        
        for(int i =0; i<numRows; i++){
            if(i == 0 || i == numRows-1){
                for(int j=0; i+j<s.size(); j+=round){
                    res += s[i + j];
                }
            }

            else{
                for(int j=0; j<s.size(); j+=round){
                    int tmp = i + j + round - i * 2;
                    if(i + j < s.size())    res += s[i + j];
                    if(tmp < s.size())  res += s[tmp];
                }
            }
        }
        return res;
    }
};

// A       J       A
// B     H F     S Q
// C   G   V   F   ;  
// D F     A F     P
// E       L       I

// numRows = 5 (8) (6, 2) (4, 4) (2, 6) (8)

// numRows = 4 (6) (4, 2) (2, 4) (6)
// numRows = 3 (4) (2, 2) (4)