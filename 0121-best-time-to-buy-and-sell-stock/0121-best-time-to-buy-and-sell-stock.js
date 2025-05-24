/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function(prices) {
    let min_num = prices[0]
    let res = 0
    for(let i=0; i<prices.length; i++){
        min_num = Math.min(min_num, prices[i])
        res = Math.max(res, prices[i] - min_num)
    }
    return res
};