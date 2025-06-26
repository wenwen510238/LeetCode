class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> res;
        int n = intervals.size();
        int current = 0;
        while(current < n && newInterval[0] > intervals[current][1]){
            res.push_back(intervals[current]);
            current++;
        }

        while(current < n && newInterval[1] >= intervals[current][0]){
            newInterval[0] = min(newInterval[0], intervals[current][0]);
            newInterval[1] = max(newInterval[1], intervals[current][1]);
            current++;
        }
        res.push_back({newInterval[0], newInterval[1]});
        while(current < n){
            res.push_back(intervals[current]);
            current++;
        }
        return res;
    }
};