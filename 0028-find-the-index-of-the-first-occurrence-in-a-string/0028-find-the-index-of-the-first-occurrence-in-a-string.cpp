class Solution {
public:
    int strStr(string haystack, string needle) {
        vector<int> lps = buildLPS(needle);
        int sub = 0;
        int main = 0;
        int res = -1;
        while(main < haystack.size()){
            if(needle[sub] == haystack[main]){
                main++;
                sub++;
            }
            else{
                if(sub == 0)    main ++;
                else    sub = lps[sub-1];
            }
            if(sub == needle.size())    return main - needle.size();
        }
        return -1;
    }

    vector<int> buildLPS(string needle){
        int n = needle.size();
        vector<int> lps(n, 0);
        int part = 1; //partial string pointer
        int whole = 0; //whole string pointer

        while(part < n) {
            if(needle[part] == needle[whole]){
                part++;
                whole++;
                lps[part-1] = whole; 
            }
            else if(whole <= 0){
                lps[part] = 0;
                part++;
            }
            else    whole = lps[whole - 1];
        }   
        return lps;
    }
};