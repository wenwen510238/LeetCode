class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for(int i=0; i<points.size(); i++){
            int dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
            pq.push({dis, i});
        }
        vector<vector<int>> res;
        while(!pq.empty() && res.size()<k){
            auto [_, idx] = pq.top();
            pq.pop();
            res.push_back(points[idx]);
        }
        return res;
    }
};