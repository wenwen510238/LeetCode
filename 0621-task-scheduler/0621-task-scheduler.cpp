class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letter(26, 0);
        for(auto c: tasks){
            letter[c-'A']++;
        }
        int maxf = 0;
        for(int i: letter){
            maxf = max(maxf, i);
        }
        int cntMax = 0;
        for(int i: letter){
            if(i == maxf) cntMax++;
        }
        int res = (maxf - 1) * (n + 1) + cntMax;
        int size = tasks.size();
        return max(size, res);
    }
};