class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        unordered_map<int, vector<int>> mp;
        vector<int> res(n, 0);
        stack<int> st;
    
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[i] > st.top()){
                int idx = mp[st.top()].back();
                res[idx] = i - idx;
                mp[st.top()].pop_back();
                st.pop();
            }
            mp[temperatures[i]].push_back(i);
            st.push(temperatures[i]);
        }
        return res;
    }
};