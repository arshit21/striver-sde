class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int todayPrice;
        int currProfit;
        int Profit = 0;
        int minVal = prices[0];
        for(int i = 1; i < prices.size(); i++){
            todayPrice = prices[i];
            currProfit = todayPrice - minVal;
            if(currProfit > Profit){
                Profit = currProfit;
            }
            minVal = min(minVal, prices[i]);
        }
        return Profit;
    }
};