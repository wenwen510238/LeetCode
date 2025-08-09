class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> letter(26, 0);
        for(auto c: tasks){
            letter[c-'A']++;
        }
        priority_queue<int> pq;
        for(int i: letter){
            if(i != 0) pq.push(i);
        }

        queue<pair<int, int>> cool;
        int time = 0;
        while(!pq.empty() || !cool.empty()){
            time++;

            if(!pq.empty()){
                int c = pq.top();
                pq.pop();
                if(--c > 0) cool.push({time + n, c});
            }

            if(!cool.empty() && cool.front().first == time){
                pq.push(cool.front().second);
                cool.pop();
            }
        }
        return time;
    }
};