class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, start = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(prices[i] < prices[i-1]){
                res = res + prices[i-1] - start;
                start = prices[i];
            }
            else if(i == prices.size()-1){
                if(prices[i] >= prices[i-1])    res = res + prices[i] - start;
            }
        }   
        return res;
    }
};

