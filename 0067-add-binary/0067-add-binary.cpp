class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int pa = a.size() - 1;
        int pb = b.size() - 1;
        int c = 0;
        while(pa >= 0 || pb >= 0 || c > 0){
            int sum = c;
            if(pa >= 0) sum += a[pa--] - '0';
            if(pb >= 0) sum += b[pb--] - '0';
            res += '0' + (sum & 1);
            c = sum >> 1;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};