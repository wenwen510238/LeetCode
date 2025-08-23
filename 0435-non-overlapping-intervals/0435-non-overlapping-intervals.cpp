class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
            return a[1] < b[1];
        });

        int remove = 0;
        int prevEnd = INT_MIN;
        for(auto& i: intervals){
            if(i[0] >= prevEnd) prevEnd = i[1]; 
            else remove++;
        }
        return remove;
    }
};