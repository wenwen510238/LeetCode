class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, min = INT_MAX;
        for(int price: prices){
            if(price < min) min = price;
            else res = max(res, price - min);
        }
        return res;
    }
};